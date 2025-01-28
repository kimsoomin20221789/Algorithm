#include <bits/stdc++.h>
using namespace std;

int arr[403][403];
int visited[403];
int n, k;

bool floydWarshall(int beforeAccident, int afterAccident) {
    for (int i=1; i<=n; i++) {
        if (arr[beforeAccident][i] && !visited[i]) {
            visited[i] = true;
            if (i == afterAccident) {
                return true;
            } else {
                if (floydWarshall(i, afterAccident)) {
                    return true;
                }
            }
        }
    }
    return false;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> k;
    for (int i=0; i<k; i++) {
        int beforeAccident; int afterAccident;
        cin >> beforeAccident >> afterAccident;
        arr[beforeAccident][afterAccident] = true;
    }

    int answerCnt; cin >> answerCnt;
    while (answerCnt--) {
        int beforeAccident; int afterAccident;
        cin >> beforeAccident >> afterAccident;
        if (floydWarshall(beforeAccident, afterAccident)) {
            cout << "-1" << "\n";
            memset(visited, false, sizeof(visited));
        } else if (floydWarshall(afterAccident, beforeAccident)) {
            cout << "1" << "\n";
            memset(visited, false, sizeof(visited));
        } else {
            cout << "0" << "\n";
            memset(visited, false, sizeof(visited));
        }
    }
}