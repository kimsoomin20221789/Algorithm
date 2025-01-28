// 프림알고리즘 - MST
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int V; int E; 
vector<pair<int, ll>> val[10003];
bool visited[10003];
priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> V >> E;
    for (int i=0; i<E; i++) {
        int a; int b; ll c; cin >> a >> b >> c;
        val[a].push_back({b, c});
        val[b].push_back({a, c});
    }
    
    int cnt = 0;
    pq.push({0, 1});
    ll answer = 0;

    while (cnt < V) {
        auto node = pq.top();
        pq.pop();
        if (visited[node.second]) {
            continue;
        }

        answer += node.first;
        visited[node.second] = true;
        cnt++;

        for (auto i : val[node.second]) {
            if (visited[i.first]) {continue;}
            pq.push({i.second, i.first});
        }
    }
    
    cout << answer;

}