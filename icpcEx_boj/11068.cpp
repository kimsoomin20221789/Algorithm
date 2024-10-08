#include <bits/stdc++.h>
using namespace std;
vector<int> v;

int decalcomani() {
    int n = v.size() - 1;
    for (int i = 0; i <= n / 2; i++) {
        if (v[i] != v[n - i]) {
            return 0;
        }
    }
    return 1;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int T; cin >> T;
    
    while (T--) {
        int ans = 0;
        int x; cin >> x;
        
        for (int i = 2; i <= 64; i++) {
            int base = i;
            int temp = x;
            v.clear();
            
            // 진법 변환
            while (temp > 0) {
                v.push_back(temp % base);
                temp /= base;
            }
            
            // 대칭인지 확인
            if (decalcomani()) {
                ans = 1;
                break;
            }
        }
        cout << ans << "\n";
    }
}
