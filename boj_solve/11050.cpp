#include <bits/stdc++.h>
using namespace std;
int arr[11][11];

int main() {

    ios::sync_with_stdio(0);
    cin.tie(0);

    int N; int K; cin >> N >> K;
    arr[1][0] = 1;
    arr[1][1] = 1;
    for (int i=1; i<=N; i++) {
        arr[i][0] = 1;
        for (int j=1; j<i; j++) {
            arr[i][j] = arr[i-1][j-1] + arr[i-1][j];
        }
        arr[i][i] = 1;
    }

    cout << arr[N][K];
}