#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    while (true) {
        int x; cin >> x;
        int arr[300000] = {0};
        if (x == 0) {
            break;
        }
        int cnt = 0;
        for (int i=2; i*i<=2*x; i++) {
            for (int j = i*i; j<=2*x; j+=i) {
                if (j>x && j<=2*x && (arr[j] != true)) {
                    arr[j] = true;
                    cnt++;
                }
            }
        }

        cout << x-cnt << "\n";
    }
}