#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
typedef pair<int, int> pii;
vector<pair<int, int> > v[2003];
bool visited[2003];

priority_queue<pii, vector<pii>, greater<pii> > pq;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N; int M; int S;
    cin >> N >> M >> S;
    
    for (int i=0; i<M; i++) {
        int a; int b; int c; cin >> a >> b >> c;
        v[a].push_back({b,c});
        v[b].push_back({a,c});
    }

    pq.push({0, S});

    int cnt = 0;
    ll total = 0;
    while (!pq.empty() && cnt < N) {
        auto i = pq.top();
        pq.pop();

        int vertex = i.second;
        int edge = i.first;

        if (visited[vertex]) {
            continue;
        }

        visited[vertex] = true;
        cnt++; 
        total += edge;

        for (auto k : v[vertex]) {
            if (!visited[k.first]) {
                pq.push({k.second, k.first});
            }
        }
    }

    for (int i=0; i<N; i++) {
        int x; cin >> x;
    }
    cout << total;
    
}