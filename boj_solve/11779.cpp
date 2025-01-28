#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
#define LINF LLONG_MAX
vector<pii> v[1003];
int preVertex[1003];
ll shortDistance[1003];
priority_queue<pii, vector<pii>, greater<pii>> pq;

void daikstra(int start, int end) {
    pq.push({0, start});
    shortDistance[start] = 0;
    while (!pq.empty()) {
        auto currentSet = pq.top();
        pq.pop();

        int edge = currentSet.first;
        int vertex = currentSet.second;
        if (vertex == end) {
            return;
        }
        if (shortDistance[vertex] != edge){
            continue;
        }
         
        for (auto i : v[vertex]) {
            if (edge+i.second < shortDistance[i.first]) {
                shortDistance[i.first] = edge + i.second;
                pq.push({edge + i.second, i.first});
                preVertex[i.first] = vertex;
            }
        }
    }
}
int main() {
    int n; int m; cin >> n >> m;
    fill(shortDistance, shortDistance+n+1, LINF);
    for (int i=0; i<m; i++) {
        int a; int b; int c; cin >> a >> b >> c;
        v[a].push_back({b, c});
    }

    int start; cin >> start;
    int end; cin >> end;

    daikstra(start, end);

    cout << shortDistance[end] << "\n";

    stack<int> ans;
    
    int currentVertex = end;
    
    while (currentVertex != start) {
        ans.push(currentVertex);
        currentVertex = preVertex[currentVertex];
    }

    ans.push(start);

    cout << ans.size() << "\n";

    while (!ans.empty()) {
        cout << ans.top() << " ";
        ans.pop();
    }
}