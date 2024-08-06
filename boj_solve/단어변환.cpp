#include <string>
#include <vector>
#include <queue>
using namespace std;

bool different(string a, string b){
    int len = a.length();
    int cnt = 0;
    for (int i=0; i<len; i++){
        if (a[i] != b[i]){
            cnt++;
        }
    }
    if (cnt ==1){
        return true;
    } return false;
}
int solution(string begin, string target, vector<string> words) {
    // int answer = 0;
    // return answer;
    int dist[50] = {0};
    //different_one 한개만 다른지 확인하는 함수 만들기

    //hit에서 시작해서 words탐색후 한개만 다르면 queue에 넣고 dist = +1
    queue<pair<string, int> > Q;
    Q.push(make_pair(begin , 0));
    dist[0] = 0;
    //queue가 빌때까지 하고 다 비면 0을 return
    while (!Q.empty()){
        pair<string, int> h = Q.front(); Q.pop();
        for (int i=1; i<=words.size(); i++){
            if (dist[i] > 0) continue;
            if (different(words.at(i-1), h.first)){
                Q.push(make_pair(words.at(i-1), i));
                dist[i] = dist[h.second]+1;
                if (words.at(i-1) == target){
                    return dist[i];
                }
            }
        }
    }
    return 0;
}