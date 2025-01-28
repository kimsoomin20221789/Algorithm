#include <bits/stdc++.h>
using namespace std;
int answer = 0;
int isused1[16][16];

int N;
void backTrack(int cnt) {
    if (cnt == N) {
        answer++;
        return;
    }
    for (int j=0; j<N; j++) {
        if (!isused1[cnt][j]) {
            vector<pair<int, int>> v;
            for (int a=cnt+1; a<N; a++) {
                for (int b=0; b<N; b++) {
                    if (!isused1[a][b]) {
                        isused1[a][b] = true;
                        v.push_back({a, b});
                    }
                }
            }
            backTrack(cnt+1);
            while (!v.empty()) {
                pair<int, int> x = v.at(v.size()-1);
                isused1[x.first][x.second] = false;
            }
        }
    }
}


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    backTrack(0);
    cout << answer;
}