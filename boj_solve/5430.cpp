#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int T; cin >> T;

    while (T--) {
        string p; cin >> p;
        int n; cin >> n;
        
        deque<int> dq;
        char c;
        for (int i=0; i<n; i++) {
            cin >> c;
            int x; cin >> x;
            dq.push_back(x);
        }
        cin >> c;
        if (n==0) {
            cin >> c;
        }

        bool isError = false;
        bool isFrontForward = true;
        for (auto x : p) {
            if (x == 'R') {
                isFrontForward = !isFrontForward;
            } else if (x == 'D') {
                if (dq.empty()) {
                    isError = true;
                    break;
                } else {
                    if (isFrontForward) {
                        dq.pop_front();
                    } else {
                        dq.pop_back();
                    }
                }
            }
        }

        if (isError) {
            cout << "error" << "\n";
        } else {
            cout << "[";
            int maxSize = dq.size();
            for (int i=0; i<maxSize; i++) {
                if (isFrontForward) {
                    cout << dq.front();
                    dq.pop_front();
                    if (i == maxSize-1){
                        continue;
                    } 
                    cout << ",";
                } else {
                    cout << dq.back();
                    dq.pop_back();
                    if (i == maxSize-1){
                        continue;
                    } 
                    cout << ",";
                }
            }
            cout << "]" << "\n";
        }

    }
}