#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int N; cin >> N;
    long long total = 0;
    long long totalSum = 0;
    vector<int> v;

    for (int i=0; i<N; i++) {
        int x; cin >> x;
        totalSum += x;
        v.push_back(x);
    }

    for (int i=0; i<v.size(); i++) {
        int x = v[i];
        total += (totalSum - x) * x;
    }

    cout << total/2;
}