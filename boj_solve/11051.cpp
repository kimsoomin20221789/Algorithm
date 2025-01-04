#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MAX_V 1000
#define MOD 10007
ll arr[MAX_V+3][MAX_V+3];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int N; int K; cin >> N >> K;


    for (int i=0; i<=N; i++) {
        for (int j=0; j<=i; j++) {
            if (j==0 || i==j) {
                arr[i][j] = 1;
            } else {
                arr[i][j] = (arr[i-1][j-1] + arr[i-1][j]) % MOD;
            }
        }
    }

    cout << arr[N][K];
}