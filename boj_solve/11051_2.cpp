// 페르마의 소법칙을 이용해 풀어보기
#include <bits/stdc++.h>
using namespace std;
#define MAX_VAL 1000
#define MOD 10007

// x! % mod
int factorialWithMod(int n) {
    int total = 1;
    for (int i=1; i<=n; i++) {
        total = (total%MOD * i%MOD) % MOD;
    }
    return total;
}

// (x!)^-1 % mod
// 페르마의 소정리를 이용해 (x!)^mod-2 % mod 로 계산
int inverseFactorialWithMod(int n) {
    int total = 1;
    for (int i=0; i<MOD-2; i++) {
        total = ((total%MOD) * (factorialWithMod(n)%MOD)) % MOD;
    }
    return total;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int N; int K; cin >> N >> K;
    cout << (factorialWithMod(N) % MOD *  inverseFactorialWithMod(N-K) % MOD * inverseFactorialWithMod(K) % MOD) % MOD;
}