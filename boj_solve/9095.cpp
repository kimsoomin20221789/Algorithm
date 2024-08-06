#include <bits/stdc++.h>
using namespace std;
int D[11];

//미리 다 구해놓는게 효율적임.
//1. 테이블 정의하기
//D[i]는 i를 1,2,3의 합으로 나타내는 방법
//2. 점화식 찾기
//D[i] = D[i-1] + D[i-2] + D[i-3]
//3. 초기값 정하기
int main (){
    int T;
    cin >> T;
    D[1] = 1;
    D[2] = 2;
    D[3] = 4;
    for (int i=4; i<11; i++){
        D[i] = D[i-1] + D[i-2] + D[i-3];
    }
    for (int i=0; i<T; i++){
        int n;
        cin >> n;
        cout << D[n] << "\n";
    }
}