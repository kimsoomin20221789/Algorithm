#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using namespace std;

typedef long long ll;
typedef pair<ll, int> pli;
// 정렬이랑 반대
struct comp {
	bool operator()(pli a, pli b){
		return a.first > b.first;
	}
};
priority_queue<pli, vector<pli>, comp> pq; // Min Heap
ll A, B, C, D, x[10000];

bool visited[10000];

ll f(ll i, ll j) {
	if (i > j) swap(i, j);
	return (((__int128)x[i] * A + (__int128)x[j] * B) % C) ^ D;
}

int main() {
	fastio;
	//input
	ll n; cin >> n >> A >> B >> C >> D;
	for (ll i = 0; i < n; i++) cin >> x[i];

	//MST
	ll ans = 0;
	vector<ll> dist(n, LLONG_MAX); 
    dist[0] = 0;
 	for (ll p = 0; p < n; p++) {
		ll cur = 0;
		ll mn = LLONG_MAX;

        // 전체 노드를 돌면서 unvisited 중 dist가 가장 작은 노드 구하기
        // cur = 그 노드 vertex
        // mn = 그 노드의 edge
        // pq : unvisited 중 front 찾기
		for (ll i = 0; i < n; i++) {
			if (!visited[i] && mn > dist[i]) {
				mn = dist[i];
				cur = i;
			}
		}

        // pq : 값 update 코드
		visited[cur] = 1;
        ans += dist[cur];

        // 배열 업데이트 해주기.
        // pq: pq에 추가로 넣기
		for (ll i = 0; i < n; i++) {
			if (visited[i]) continue;
			if (f(cur, i) > dist[i]) continue;
			dist[i] = f(cur, i);
		}
	}
	cout << ans << '\n';
}