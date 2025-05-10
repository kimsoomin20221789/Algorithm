#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int N; cin >> N;

    vector<int> v;
    for (int i=0; i<N; i++) {
        int x; cin >> x; v.push_back(x);
    }
    sort(v.begin(), v.end());

    int answer = 0;
    for (auto i : v) {
        answer += i*N;
        N--;
    }
    
    cout << answer;
}