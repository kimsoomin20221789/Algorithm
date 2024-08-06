//1. 테이블 정의하기
//D[i] = i번째 계단에서 얻을수 있는 점수의 최댓값
//D[1] = 1번째 계단에서 얻을수 있는.. -> D[1] = c[1]
//D[2] = 2번째 계단에서 .. -> D[2] = max(c[1] + c[2] , c[2])
//D[3] = D[2]
//D[i] = D[i-2] + c[i] 
#include <bits/stdc++.h>
using namespace std;

int stairs[301];
int D[301][2];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n; cin >> n;
    for (int i=0; i<n; i++){
        cin >> stairs[i+1];
    }

    D[1][1] = stairs[1];
    D[1][2] = 0;
    D[2][1] = stairs[2];
    D[2][2] = stairs[1] + stairs[2];

    for (int i=3; i<=n; i++){
        D[i][1] = max(D[i-2][1], D[i-2][2]) + stairs[i];
        D[i][2] = D[i-1][1] + stairs[i];
    }
    
    cout << max(D[n][1], D[n][2]);
}