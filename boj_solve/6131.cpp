#include <bits/stdc++.h>
using namespace std;

int main() {
    int N; cin >> N;
    int ans = 0;
    for (int b=1; b<=500; b++) {
        for (int a=b+1; a<=500; a++) {
            if (a*a - b*b == N ) {
                ans++;
            }
        }
    }

    cout << ans;
}