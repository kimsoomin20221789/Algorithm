#include <bits/stdc++.h>
#define X first
#define Y second
using namespace std;

vector<pair<int, int> > val[1003];
int minVal[1003];
priority_queue<pair<int, int> > pq;
const int INF = 987654321;

int N; int M;
int st; int des;

int main() {
    cin >> N; cin >> M;
    for (int i=0; i<M; i++) {
        int a; int b; int c;
        cin >> a >> b >> c;
        val[a].push_back({b, c});
    }

    cin >> st >> des;


    // minVal 초기화
    fill(minVal, minVal+N+1, INF);

    minVal[st] = 0;

    pq.push({st, minVal[st]});

    while (!pq.empty()) {

        // 큐에서 우선순위 빼기 -> 고정값 후보들 빼기
        auto cur = pq.top(); pq.pop();

        // minVal에 이미 고정이 되어있다면 패스!
        if (minVal[cur.X] != cur.Y) continue;

        // 큐에서 뺀 아이들을 minVal에 고정시키기!
        for (auto nxt : val[cur.X]) {
            if (minVal[nxt.X] > minVal[cur.X] + nxt.Y) {
                // 고정값 당첨!
                minVal[nxt.X] = minVal[cur.X] + nxt.Y;
                pq.push({nxt.X, minVal[nxt.X]});
                // 큐에 넣는 것들은 고정이 아닌, 후보들!
            }
        }
    }

    cout << minVal[des];
    
}