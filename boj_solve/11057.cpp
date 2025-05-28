#include <bits/stdc++.h>
using namespace std;

int arr[1003][10];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int N; cin >> N;
    
    for (int i=0; i<=9; i++) {
        arr[1][i] = 10 - i;
    }


    for (int i=2; i<=N; i++) {
        for (int j=9; j>=0; j--) {
            if (j==9) {
                arr[i][j] = arr[i-1][j]%10007;
            } else {
                arr[i][j] = (arr[i-1][j]%10007 + arr[i][j+1]%10007)%10007;
            }
        }
    }

    cout << arr[N][0]%10007;
}