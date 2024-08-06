#include <iostream>
#include <vector>
#include <deque>
using namespace std;
int N; int M;
bool visited[10];
int col[10];
void dfs(int cnt){
    if (cnt == M){
        for(int i=0; i<M; ++i){
            cout << col[i] << " ";
        }
        cout << "\n";
        return;
    }
    for (int i=1; i<N+1; i++){
        if (visited[i]){
            continue;
        }
        visited[i] = true;
        col[cnt] = i;
        dfs(cnt+1);
        visited[i] = false;
    }
}

int main(){
    
    cin >> N >> M;

    dfs(0);

}