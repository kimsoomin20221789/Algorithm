#include <string>
#include <vector>
#include <queue>
using namespace std;

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    int visited[200] = {0};
    for (int i=0; i<n; i++){
        if (visited[i]==0){
            // bfs(i);
            queue<int> q;
            visited[i] = true;
            q.push(i);
            while (!q.empty()){
                int x = q.front(); q.pop();
                for (int j=0; j<n; j++){
                    if (j == x) continue;
                    if (computers.at(x).at(j) == 1 && visited[j] == 0){
                        visited[j] = true;
                        q.push(j);
                    }
                }
            }

            answer++;
        }
        
    }
    return answer;
}