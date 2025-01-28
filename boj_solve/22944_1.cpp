#include <bits/stdc++.h>
using namespace std;
char arr[502][502];
int N; int H; int D;
vector<pair<int, int>> um;
pair<int, int> st;
pair<int, int> en;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> H >> D;
    for (int i=0; i<N; i++) {
        for (int j=0; j<N; j++) {
            char k;
            cin >> k;
            if (k == 'S') {
                st.first = i;
                st.second = j;
            } else if (k == 'U') {
                um.push_back({i, j});
            } else if (k == 'E') {
                en.first = i;
                en.second = j;
            }
            arr[i][j] = k;
        }
    }
}