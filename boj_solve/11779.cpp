#include <bits/stdc++.h>
#define X first
#define Y second
using namespace std;
int n; //최대 1000
int m; // 버스의 개수, 최대 100000
vector<pair<int, int>>  val[1005];
const int INF = 987654321;

int d[1005];
int prior[1005];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    fill(d, d+n+1, INF);
    int ansX;
    int ansY;
    for (int i=0; i<m; i++) {
        int a; int b; int c;
        cin >> a >> b >> c;
        val[a].push_back({c,b});
    }
    cin >> ansX >> ansY;

    priority_queue<pair<int, int>, vector<pair<int, int>>,
    greater<pair<int, int>>> pq;

    d[ansX] = 0;
    pq.push({d[ansX], ansX});

    while (!pq.empty()) {
        auto cur = pq.top(); pq.pop();
        if (d[cur.Y] != cur.X) continue;
        for (auto nxt : val[cur.Y]) {
            // 새롭게 업데이트 시킨 값이 더 클 때 -> 기존 값 그대로!
            if (d[nxt.Y] <= d[cur.Y] + nxt.X) continue;
            // 새롭게 업데이트 시킨 값이 더 작을 때 => 업데이트!
            d[nxt.Y] = d[cur.Y] + nxt.X;
            prior[nxt.Y] = cur.Y;
            // 우선순위큐에도 새로운 값들 넣어주기
            pq.push({d[nxt.Y], nxt.Y});
        }
    }

    cout << d[ansY] << "\n";
    
    int before = ansY;
    vector<int> v;
    while (true) {
        if (before == 0 || before == INF)  {
            break;
        } else {
            v.push_back(before);
            before = prior[before];
        }
    }

    reverse(v.begin(), v.end());

    cout << v.size() << "\n";

    for (int i=0; i<v.size(); i++) {
        cout << v[i] << " ";
    }
    
}