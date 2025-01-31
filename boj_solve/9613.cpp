#include <bits/stdc++.h>
using namespace std;
int gcd(int a, int b) {
    if (b == 0) {
        return a;
    }
    return gcd(b, a%b);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int T; cin >> T;
    while (T--) {
        long long ans = 0;
        int n; cin >> n;
        
        vector<int> v;

        int x; cin >> x;
        v.push_back(x);
        for (int i=1; i<n; i++) {
            int z; cin >> z;
            for (auto y : v) {
                if (z < y) {
                    ans += gcd(y, z);
                } else {
                    ans += gcd(z, y);
          
                }
            }
            v.push_back(z);
        }
        cout << ans << "\n";   
    }
}