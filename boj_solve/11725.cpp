#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int arr[100001];
int visited[100001];
vector<int> v[100001];

void dfs(int k){
    visited[k] = true;
    for (int i=0; i<v[k].size(); i++){
        int next = v[k][i];
        if (!visited[next]){
            arr[next] = k;
            dfs(next);
        }
    }
}

int main(void){
    ios::sync_with_stdio(0); cin.tie(0);
    int N;
    // int visited[N+1];
    cin >> N;
    // int visited[N+1];


    int a, b;
    for (int i=0; i<N-1; i++){    
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }

    dfs(1);
    for (int i=2; i<N+1; i++){
        cout << arr[i] << "\n";
    }
}