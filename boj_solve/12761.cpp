#include <bits/stdc++.h>
using namespace std;
int A; int B;
int N; int M;

int comp(int x, int i) {
    if (i==0) {
        return x+1;
    } else if (i==1) {
        return x-1;
    } else if (i==2) {
        return x*A;
    } else if (i==3) {
        return x*B;
    } else if (i==4) {
        return x+A;
    } else if (i==5) {
        return x-A;
    } else if (i==6) {
        return x+B;
    } else if (i==7) {
        return x-B;
    } else {
        return 0;
    }
}

bool visited[100003];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> A >> B >> N >> M;

    queue<pair<int, int>> q;
    q.push({N, 0});
    visited[N] = true;
    
    while (!q.empty()) {
        auto cur = q.front();
        q.pop();

        if (cur.first == M) {
            cout << cur.second;
            break;
        }

        for (int i=0; i<8; i++) {
            int nxt = comp(cur.first, i);
            if (nxt < 0 || nxt > 100000) {continue;}
            if (visited[nxt]) { continue; }
            visited[nxt] = true;
            q.push({nxt, cur.second+1});
        }
    }
}