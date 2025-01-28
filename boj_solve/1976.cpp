#include <bits/stdc++.h>
using namespace std;
vector<int> v[203];
bool visited[203];

void dfs(int src) {
	visited[src] = true;
	for (auto i : v[src] ) {
		if (!visited[i]){
			dfs(i);
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N; int M; cin >> N >> M;

	for (int i=1; i<=N; i++) {
		for (int j=1; j<=N; j++) {
			int a; cin >> a;
			if (a==1) {
				v[i].push_back(j);
			}
		}
	}
	int a; cin >> a;
	dfs(a);
	bool isYes = true;
	for (int i=0; i<M-1; i++) {
		int x; cin >> x;
		if (!visited[x]) {
			isYes = false; 
			break;
		}
	}

	if (isYes) {
		cout << "YES";
	} else {
		cout << "NO";
	}
}