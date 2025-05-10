#include <bits/stdc++.h>
using namespace std;
int visited[2000000];
stack<int> s;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int N; cin >> N;

    int lastVal = 0;

    if (N%2 == 0) {
        lastVal = 1;
    } else {
        lastVal = 2;
    }
    int x = N;
    for (int i=0; i<N; i++) {
        s.push(x);
        visited[x] = true;
        
        if (x + lastVal > N || visited[x+lastVal]) {
            x = x-lastVal;
        } else {
            x = x+lastVal;
        }

        if (lastVal == 1) {
            lastVal = 2;
        } else {
            lastVal = 1;
        }
    }

    cout << "YES" << "\n";
    
    while (!s.empty()) {
        cout << s.top() << " ";
        s.pop();
    }
}