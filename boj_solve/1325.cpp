#include <iostream>
#include <vector>
#include <queue>
using namespace std;


vector<int> v[10001];
queue<int> result[10001];
queue<int> q;

int bfs(int s){
    int cnt = 0;
    int visited[10001] = {0};
    
    visited[s] = true;
    q.push(s);
    int a;
    while(!q.empty()){
        a = q.front();
        q.pop();
        for (int i=0; i<v[a].size(); i++){
            if (visited[v[a][i]]==0){
                q.push(v[a][i]);
                visited[v[a][i]] = 1;
                cnt++;
            }
        }
    }

    return cnt;
}

int main(){

    int N;
    int M;
    cin >> N >> M;
    int a,b; 
    for (int i=0; i<M; i++){
        
        cin >> a >> b;
        v[b].push_back(a);
    }
    int edge = 1;
    int newEdge;
    for (int i=1; i<=N; i++){
        newEdge = bfs(i);
        
        if (newEdge >= edge) {
            edge = newEdge;
            result[newEdge].push(i);
            
           
        }
    }
    int j = result[edge].size();
    
    for (int i=0; i<j; i++){
        cout << result[edge].front() << " ";
        result[edge].pop();
    }

}