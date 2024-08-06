#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
int N; int M; int V;
vector<int> graph[1001];
int visited[1001];

void dfs(int s){
    visited[s] = 1;
    cout << s << " ";
    for (int i=0; i<(int)(graph[s].size()); i++){
        int y = graph[s][i];
        if (!visited[y]){
            dfs(y);
        }
    }
}

void bfs(int s){

    queue<int> q;
    q.push(s);
    visited[s] = 1;
    while (!q.empty()){
        int v = q.front();
        q.pop();
        cout << v << " ";
        for (int i=0; i<(int)(graph[v].size()); i++){
            if (!visited[graph[v][i]]){
                q.push(graph[v][i]);
                visited[graph[v][i]] = 1;
            }

        }
    }

}

void INIT(){
    for(int i=0; i<1001; i++) visited[i]=0;
}

int main(void){
    int a; int b;
    cin >> N >> M >> V;
    for (int i=0; i<M; i++){
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
        sort(graph[a].begin(), graph[a].end());
        sort(graph[b].begin(), graph[b].end());
    }
    dfs(V);
    cout << "\n";
    INIT();
    bfs(V);
}