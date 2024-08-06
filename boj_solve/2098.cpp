//s[i] = 외판원이 도시 i에서 시작할때의 순환 최소 경로
//s[i]
//D[i][A] = i노드에서 A집합 노드들을 거쳐 시작점까지 가는 최소경로
//D[i][A] = minimum(D[i])

//D[i][A] = minimum(D[j][A-j] + W[i][j]) & j는 A안에 있음.
//D[i][A] = 노드 i 에서 시작점까지 가는데 A에 있는 애들을 다 거치고 시작점까지 가는 최소 경로 
//D[j][A-j]= A중 한개인 j 로부터 시작점까지 가는데 j를뺀 A에 있는 애들을 다 거치고 시작점까지 가는 경로. + W[i][j]

#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int N;
int W[16][16];

int main(){
    cin >> N;
    for (int i=0; i<N; i++){
        for (int j=0; j<N; j++){
            cin >> W[i][j];
        }
    }

    D[]

}



// there are four nodes in example graph (graph is 1-based)
const int n = 4;
// give appropriate maximum to avoid overflow
const int MAX = 1000000;

// dist[i][j] represents shortest distance to go from i to j
// this matrix can be calculated for any given graph using
// all-pair shortest path algorithms
int dist[n + 1][n + 1] = {
	{ 0, 0, 0, 0, 0 }, { 0, 0, 10, 15, 20 },
	{ 0, 10, 0, 25, 25 }, { 0, 15, 25, 0, 30 },
	{ 0, 20, 25, 30, 0 },
};

// memoization for top down recursion
int memo[n + 1][1 << (n + 1)];

int fun(int i, int mask)
{
	// base case
	// if only ith bit and 1st bit is set in our mask,
	// it implies we have visited all other nodes already
	if (mask == ((1 << i) | 3))
		return dist[1][i];
	// memoization
	if (memo[i][mask] != 0)
		return memo[i][mask];

	int res = MAX; // result of this sub-problem

	// we have to travel all nodes j in mask and end the
	// path at ith node so for every node j in mask,
	// recursively calculate cost of travelling all nodes in
	// mask except i and then travel back from node j to
	// node i taking the shortest path take the minimum of
	// all possible j nodes

	for (int j = 1; j <= n; j++)
		if ((mask & (1 << j)) && j != i && j != 1)
			res = std::min(res, fun(j, mask & (~(1 << i)))
									+ dist[j][i]);
	return memo[i][mask] = res;
}
// Driver program to test above logic
int main()
{
	int ans = MAX;
	for (int i = 1; i <= n; i++)
		// try to go from node 1 visiting all nodes in
		// between to i then return from i taking the
		// shortest route to 1
		ans = std::min(ans, fun(i, (1 << (n + 1)) - 1) + dist[i][1]);

	printf("The cost of most efficient tour = %d", ans);

	return 0;
}

// This code is contributed by Serjeel Ranjan
