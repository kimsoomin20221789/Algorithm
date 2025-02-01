#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);


    string s; cin >> s;
    int arr[10] = {0};

    int rangeSize = '0';
    for (auto x : s) {
        arr[x-rangeSize]++;
    }

    int x = arr['6'-rangeSize] + arr['9'-rangeSize];
    if (x%2 == 0) {
        arr['6'-rangeSize] = x/2;
        arr['9'-rangeSize] = 0;
    } else {
        arr['6'-rangeSize] = (x+1)/2;
        arr['9'-rangeSize] = 0;
    }

    int ans = 0;
    for (int i=0; i<9; i++) {
        ans = max(arr[i], ans);
    }

    cout << ans;
}