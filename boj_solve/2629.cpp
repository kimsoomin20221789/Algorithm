//dp[x][y] : x번까지의 추를 사용했을 때 y 무게를 만들 수 있는지에 대한 여부 

#include <bits/stdc++.h>
using namespace std;

int n, x, weight[31];
int h;
bool dp[31][15001];

void solve(int i, int w)
{
	if (i > n || dp[i][w]) return;
	dp[i][w] = true;
	solve(i + 1, w + weight[i]);
	solve(i + 1, abs(w - weight[i]));
	solve(i + 1, w);
}

int main()
{
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> weight[i];
	}
	solve(0, 0);

	cin >> h;

	for (int i = 0; i < h; i++)
	{
		cin >> x;

		if(x > 15000) cout << "N ";
		else if (dp[n][x]) cout << "Y ";
		else cout << "N ";
	}	
}
