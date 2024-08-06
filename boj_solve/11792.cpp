#include <iostream>
#include <vector>
using namespace std;

const int num = 1000; //원소 , 노드의 갯수
bool visited[num];
vector<int> graph[num];
vector<int> vertix;
int cnt = 0;

void dfs(int x){
		if (visited[x] == true){return;}
		visited[x] = true;



		for (int i=0; i<graph[x].size(); i++){
			int y = graph[x][i];
			if (!visited[y]){
                    dfs(y);
            }
		}

		
}

int main(){
    int N ; int M;
    cin >> N >> M;
    
    for (int i=0; i<M; i++){
        int u; int v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);

        // vertix.push_back(u);
    } 
    
    for (int i=1; i<=N; i++){
        if (!visited[i]){continue;}
        dfs(visited[i]);
    }

}