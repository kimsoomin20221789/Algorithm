#include <vector>
#include <iostream>
#include <stdio.h>
using namespace std;

bool visited[9];
vector<int> graph[9];
void dfs(int x, int y){
    int count = 0;
    visited[x][y] = 1;
    for (int i = 0; graph[x].size(); i++){
        int k = list1[x][i];
        count += 1;
        if (!visited[y]){
            dfs(k);
        }
    }
}
const int MAX = 101;
char list1[MAX][MAX];
int visited[MAX][MAX];
int main(void){
    int n;
    int m;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++){
            cin >> list1[i][j];
        }
    

}