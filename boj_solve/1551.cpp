#include <bits/stdc++.h>
using namespace std;

int main() {
    int N; int K; cin >> N >> K;

    vector<int> v;
    int x; char c;
    for (int i=0; i<N-1; i++) {
        cin >> x >> c;
        v.push_back(x);
    }
    cin >> x; v.push_back(x);

    for (int k=0; k<K; k++) {
        for (int i=0; i<v.size()-1-k; i++) {
            v[i] = v[i+1]-v[i];
        }
    }

    for (int i=0; i<v.size()-K-1; i++) {
        cout << v[i] << ",";
    }
    cout << v[v.size()-K-1];
}