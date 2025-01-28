#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n; cin >> n;
    set<string> s;

    for (int i=0; i<n; i++) {
        string name; string status;
        cin >> name >> status;
        if (status == "enter") {
            s.insert(name);
        } else {
            s.erase(name);
        }
    }
    auto it = s.end();
    for (int i=1; i<=s.size(); i++) {
        advance(it, -1);
        cout << *it << "\n";
    }
}