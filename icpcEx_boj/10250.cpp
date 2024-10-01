#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    long long T; cin >> T;
    for (int i=0; i<T; i++) {
        int H; int W; int N;
        cin >> H >> W >> N;
        int k = N % H;
        int h = (k==0) ? H : N % H;
        int w = (k==0) ? N/H : N / H + 1;
        if (w < 10) {
            string st = "0" + to_string(w);
            cout << h << st;
        } else {
            cout << h << w;
        }
        cout << "\n";
    }
}