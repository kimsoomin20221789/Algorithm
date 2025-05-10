#include <bits/stdc++.h>
using namespace std;
int arr[53];
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N; cin >> N;

    while (N--) {
        int a; cin >> a;
        arr[a]++;
    }

    for (int i=50; i>=0; i--) {
        if (arr[i] == i) {
            cout << i;
            return 0;
        }
    }

    cout << -1;
}