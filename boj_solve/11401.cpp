#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MAX_VAL  4000000
#define MOD 1000000007

// x! % mod
ll factorialWithMod(ll n) {
    ll total = 1;
    for (ll i=1; i<=n; i++) {
        total = (total%MOD * i%MOD) % MOD;
    }
    return total;
}
 
ll fastPowWithMod(ll x, ll n, ll r) {
    ll extra = 1;
 
    while (n > 1) {
        if (n & 1) {
            extra = (extra * x) % r;
        }
        x = (x * x) % r;
        n = n >> 1;
    }
    
    return (x * extra) % r;
}

// (x!)^-1 % mod
// 페르마의 소정리를 이용해 (x!)^mod-2 % mod 로 계산
ll inverseFactorialWithMod(ll n) {
    return fastPowWithMod(factorialWithMod(n), MOD-2, MOD);
}


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll N; ll K; cin >> N >> K;
    cout << (factorialWithMod(N) % MOD *  inverseFactorialWithMod(N-K) % MOD * inverseFactorialWithMod(K) % MOD) % MOD;
}