#include <bits/stdc++.h>
using namespace std;
int N;
char arr[7][7];
vector<pair<int, int>> t;
vector<pair<int, int>> x;
bool findAnswer = false;

bool checking() {

    bool returnVal = true;
    for (int i=0; i<t.size(); i++) {
        int x = t[i].first;
        int y = t[i].second;
        for (int x2=x-1; x2>=0; x2--) {
            if (arr[x2][y] == 'O') {
                break;
            }
            if (arr[x2][y] == 'S') {
                returnVal = true;
            }
        }
        if (returnVal) {
            break;
        }
        for (int x2=x+1; x2<N; x2++) {
            if (arr[x2][y] == 'O') {
                break;
            }
            if (arr[x2][y] == 'S') {
                returnVal = true;
            }
        }
        if (returnVal) {
            break;
        }

        for (int y2=y+1; y2<N; y2++) {
            if (arr[x][y2] == 'O') {
                break;
            }
            if (arr[x][y2] == 'S') {
                returnVal = true;
            }
        }
        if (returnVal) {
            break;
        }

        for (int y2=y-1; y2>=0; y2--) {
            if (arr[x][y2] == 'O') {
                break;
            }
            if (arr[x][y2] == 'S') {
                returnVal = true;
            }
        }
        if (returnVal) {
            break;
        }
    }
    return returnVal;
}

void backTracking(int i, int cnt) {
    if (cnt == 3) {
        if (checking() == true) {
            findAnswer = false;
        }
        return;
    }

    if (i >= N) {return;}
    auto cur = x[i];
    arr[cur.first][cur.second] = 'O';
    backTracking(i+1, cnt+1);
    if (findAnswer == true) {return;}
    arr[cur.first][cur.second] = 'X';
    backTracking(i+1, cnt);
    if (findAnswer == true) {return;}
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N;

    for (int i=0; i<N; i++) {
        for (int j=0; j<N; j++) {
            char c; cin >> c;
            arr[i][j] = c;

            if (c == 'X') {
                x.push_back({i, j});
            } else if (c == 'T') {
                t.push_back({i, j});
            }
        }
    }

    backTracking(0, 0);

    if (findAnswer) {
        cout << "YES";
    } else {
        cout << "NO";
    }
}