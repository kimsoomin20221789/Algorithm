#include <bits/stdc++.h>
using namespace std;
vector<string> v;

bool isConsistent(string a, string b) {
    // for (int i=0; i < b.size()-a.size()+1; i++) {
    //     if (b.substr(i, a.size()) == a) {
    //         return false;
    //     }
    // }
    if (b.substr(0, a.size()) == a) {
        return false;
    }
    return true;
}

void checkingTestcase() {
    int N; cin >> N;
    v.clear();

    for (int i=0; i<N; i++) {
        string s; cin >> s;
        v.push_back(s);
    }

    sort(v.begin(), v.end());

    if (v.size() == 0) {
        cout << "YES" << "\n";
        return;
    }

    for (int i=0; i<N-1; i++) {
        if (v[i].size() > v[i+1].size()) {continue;}
        if (!isConsistent(v[i], v[i+1])) {
            cout << "NO" << "\n";
            return;
        }
    }

    cout << "YES" << "\n";
    return;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    int T; cin >> T;

    for (int i=0; i<T; i++) {
        checkingTestcase();
    }
}