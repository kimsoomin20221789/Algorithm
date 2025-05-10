#include <bits/stdc++.h>
using namespace std;

bool visited[100003];
int arr[100003];
set<int> edge[100003];
int answer;

vector<int> cnt = {0, 0};

void dfs(int q) {
    visited[q] = true;
    cnt[arr[q]]++;

    for (auto i : edge[q]) {
        if (visited[i]) {continue;}
        dfs(i);
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int N; int M; int Q; cin >> N >> M >> Q;

    for (int i=0; i<N; i++) {
        cin >> arr[i];
    }

    for (int i=0; i<M; i++) {
        int a; int b; cin >> a >> b;
        edge[a-1].insert(b-1);
        edge[b-1].insert(a-1);
    }

    for (int i=0; i<Q; i++) {
        int x; cin >> x;
        dfs(x-1);
        if (cnt[1] > cnt[0]) {
            cout << "1" << "\n";
        } else {
            cout << "0" << "\n";
        }

        cnt = {0, 0};
        for (int i=0; i<N; i++) {
            visited[i] = false;
        }
    }
}