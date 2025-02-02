#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int A; int B; int C; int M;
    cin >> A >> B >> C >> M;
    
    long long x = (M+24*C) / (A+C);
    
    if (A > M) {
        cout << 0;
    } else {
        cout << x*B;
    }
}