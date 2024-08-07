#include <bits/stdc++.h>
using namespace std;
int n; int m;
int arr[10];
int isused[10];

void func(int k) {
    if (k == m) {
        for (int i=0; i<m; i++) {
            cout << arr[i] << " ";
        }
        cout << "\n";
    }

    for (int i=1; i<=n; i++) {
        if (!isused[i]) {
            if (k >=1 && (arr[k-1] >= i)){continue;}
            arr[k] = i;
            isused[i] = true;
            func(k+1);
            isused[i] = false;
        }
    }
}


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    func(0);
}