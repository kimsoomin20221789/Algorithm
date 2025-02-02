#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int A; int B; int C; int D; int E;
    cin >> A >> B >> C >> D >> E;
    long long ans = 0;
    if (A<0 && B<0) {
        ans += (B-A)*C;
    } else if (A<0 && B>0) {
        ans += (-A)*C + D + B*E;
    } else if (A>0 && B>0) {
        ans += (B-A)*E;
    }

    cout << ans;
}