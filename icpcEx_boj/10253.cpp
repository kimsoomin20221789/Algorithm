#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll a; ll b;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T; cin >> T;
    for (int i=0; i<T; i++) {
        cin >> a >> b;
        
        while (true) {
            if (b%a == 0) {
                b = b/a;
                a = 1;
                break;
            } else {
                int st = b / a + 1;
                a = st*a - b;
                b = st*b;
            }
        }
        cout << b << "\n";
    }
}