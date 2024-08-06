#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
#define MAX 300001
int visited[MAX];
vector<int> v[MAX];
vector<int> result;
int a = 0;

void bfs(int startNode, int distance){
    queue<int> q;
    visited[startNode] = true;
    q.push(startNode);
    
    while (!q.empty()){
        int front = q.front();
        q.pop();
        
        for (int i=0; i<v[front].size();i++){
            int next = v[front][i];
            if (!visited[next]) {
                visited[next] = visited[front]+1;
                q.push(next);
                if (visited[front] == distance) {
                    result.push_back(next);
                }
            }
        }
    }

}


int main(){
    int N, M, distance, startNode;
    cin >> N >> M >> distance >> startNode;
    for (int i=0; i<M; i++){
        int a, b;
        cin >> a >> b;
        v[a].push_back(b);
    }
    bfs(startNode, distance);
    if (result.empty()){
        cout << -1 << "\n";
    } else {
        sort(result.begin(), result.end());
        for (int i=0; i<result.size(); i++){
            cout << result[i] << "\n";
        }
    }

}