#include <string>
#include <vector>
#include <queue>
using namespace std;

int solution(vector<int> numbers, int target) {
    int answer = 0;
    queue<int> q1;
    queue<int> q2;
    q1.push(0);
    for (int i=0; i<numbers.size(); i++){
        int k = numbers.at(i);
        if (!q1.empty()){
            while (!q1.empty()){
                int a = q1.front();
                q1.pop();
                // if (a+k == target || a-k == target) answer++;  
                q2.push(a+k);
                q2.push(a-k);
            }
        } else {
            while (!q2.empty()){
                int a = q2.front();
                q2.pop();
                q1.push(a+k);
                q1.push(a-k);
            }
        }
       
    }
    if (q1.empty()){
        while (!q2.empty()) {
            int frontElement = q2.front();
            q2.pop();
            if (frontElement == target) {
                answer++;
            }
        }
    } else {
        while (!q1.empty()) {
            int frontElement = q1.front();
            q1.pop();
            if (frontElement == target) {
                answer++;
            }
        }
    }
    return answer;
}