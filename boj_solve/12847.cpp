#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n; 
    int m; 
    cin >> n >> m;
    vector<int> v;
    for (int i=0; i<n; i++) {
        int x; cin >> x;
        v.push_back(x);
    }
    int st = 1; int end = n-m;
    long long totalVal = 0;
    
    for (int i=0; i<m; i++) {
        totalVal += v[i];
    }
    long long totalVal2;
    totalVal2 = totalVal;
    for (int i=st; i<=end; i++) {
        totalVal2 -= v[i-1];
        totalVal2 += v[i+m-1];
        totalVal = max(totalVal2, totalVal);
    }

    cout << totalVal;
}