#include <bits/stdc++.h>
using namespace std;
int N; int K; 
// a, n, t
// (t, a) i , c
// default 5 -> 
unordered_set<char> cSet;
vector<char> v = {'a', 'n', 't', 'i', 'c'};
int ans = 0;
void check() {

}

void backTrack(int cnt) {

}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> K;

    for (int i=0; i<N; i++) {
        string s; cin >> s;
        for (auto c : s) {
            if (c == 'a' || c == 'n' || c == 't' ||
            c == 'i' || c == 'c') {
                continue;
            }
            cSet.insert(c);
        }
    }

    if (K<5) {
        cout << 0;
    } else {
        K -= 5;
        backTrack(0);
    }

}