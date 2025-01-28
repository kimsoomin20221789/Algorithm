#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

class UnionFind {
private:
    vector<int> parent, rank;

public:
    UnionFind(int size) {
        parent.resize(size);
        rank.resize(size);
        for (int i = 0; i < size; i++) {
            parent[i] = i;
            rank[i] = 0;
        }
    }

    int find(int u) {
        if (u != parent[u])
            parent[u] = find(parent[u]);
        return parent[u];
    }

    void unionSet(int u, int v) {
        int rootU = find(u);
        int rootV = find(v);
        if (rootU != rootV) {
            if (rank[rootU] > rank[rootV])
                parent[rootV] = rootU;
            else {
                parent[rootU] = rootV;
                if (rank[rootU] == rank[rootV])
                    rank[rootV]++;
            }
        }
    }
};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int V, E;
    cin >> V >> E;
    vector<tuple<ll, int, int>> edges;

    for (int i = 0; i < E; i++) {
        int u, v;
        ll weight;
        cin >> u >> v >> weight;
        edges.emplace_back(weight, u, v);
    }

    // 정렬 - 가중치가 낮은 간선부터 선택
    sort(edges.begin(), edges.end());

    UnionFind uf(V+1); // 유니온 파인드 초기화
    ll totalWeight = 0;

    for (auto &[weight, u, v] : edges) {
        if (uf.find(u) != uf.find(v)) {
            uf.unionSet(u, v);
            totalWeight += weight;
        }
    }

    cout << totalWeight;
    return 0;
}
