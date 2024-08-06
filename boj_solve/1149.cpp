//D[i][k] = i번째 집까지 칠할때의 최소값, i번째 집은 k색깔임
//D[i][0], D[i][1], D[i][2]

//D[i][0] = min(D[i-1][1] , D[i-1][2])+R[i][0]
//D[i][1] = min(D[i-1][0] , D[i-1][2])+R[i][1]
//D[i][2] = min(D[i-1][0] , D[i-1][1])+R[i][2]

#include <bits/stdc++.h>
using namespace std;
int D[1001][3];
int R[1001][3];
int main(){
    int n; cin >> n;
    for (int i=1; i<=n; i++){
        for (int j=0; j<3; j++){
            cin >> R[i][j];
        }
    }
    D[1][0] = R[1][0];
    D[1][1] = R[1][1];
    D[1][2] = R[1][2];
    for (int i=2; i<=n; i++){
        D[i][0] = min(D[i-1][1] , D[i-1][2])+R[i][0];
        D[i][1] = min(D[i-1][0] , D[i-1][2])+R[i][1];
        D[i][2] = min(D[i-1][0] , D[i-1][1])+R[i][2];
    }
    cout << min({D[n][0], D[n][1], D[n][2]});
}