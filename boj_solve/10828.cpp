#include <bits/stdc++.h>
using namespace std;

int main() {
    int N; cin >> N;
    stack<int> s;
    string order;
    int k; 
    for (int i=0; i<N; i++) {
        cin >> order;
        if (order == "push") {
            cin >> k;
            s.push(k);
        } else if (order == "top") {
            if (s.empty()){
                cout << -1 << "\n";
            } else {
                cout << s.top() << "\n";
            }
        } else if (order == "size") {
            cout << s.size() << "\n";
        } else if (order == "empty") {
            if (s.empty()) {
                cout << 1 << "\n";
            } else {
                cout << 0 << "\n";
            }
        } else if (order == "pop") {
            if (s.empty()){
                cout << -1 << "\n";
            } else {
                cout << s.top() << "\n";
                s.pop();
            }
        }
    }
}