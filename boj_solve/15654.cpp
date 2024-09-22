#include <bits/stdc++.h>
using namespace std;
int vis[10];
int val[10];
int N; int M; 
vector<int> ans;
void backTracking(int ind, int cnt) {
    if (cnt == M) {
        for (int i=0; i<ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << "\n";
        return;
    }

    for (int i=0; i<N; i++) {
        if (vis[i]) {continue;}
        ans.push_back(val[i]);
        vis[i] = 1;
        backTracking(val[i], cnt+1);
        vis[i] = 0;
        ans.pop_back();
    }
}


int main() {
    cin >> N >> M;

    for (int i=0; i<N; i++) {
        cin >> val[i];
    }

    sort(val, val + N);
    backTracking(-1, 0);
}