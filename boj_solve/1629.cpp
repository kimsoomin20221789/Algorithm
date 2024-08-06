#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll POW(ll a, ll b, ll c){
    ll ans = 1;
    if (b == 1) {
        return a % c;
    } else if (b == 0) {
        return 1 % c;
    }

    //귀납법 식 : b/2 를 제곱한 후, c를 나눔.
    ans = POW(a, b/2, c);
    ans = ans * ans % c;

    if (b%2 == 0) {
        return ans;
    } else {
        return ans * a % c;
    }
}


int main(){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    ll a, b, c;
    cin >> a >> b >> c;
    if (b % 2 == 0){ //짝수일때
        POW(a, b/2, c);
    } else {

    }
    cout << POW(a, b, c);
}