#include <bits/stdc++.h>
using namespace std;
string arr[50];
int N; int M;

bool ans(int squareSize) {
    for (int i=0; i+squareSize<=M; i++) {
        for (int j=0; j+squareSize<=N; j++) {
            char val = arr[j][i];
            if (arr[j+squareSize-1][i] == val && arr[j][i+squareSize-1]==val && arr[j+squareSize-1][i+squareSize-1] == val) {
                return true;
            }
        }
    }
    return false;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;

    for (int i=0; i<N; i++) {
        cin >> arr[i];
    }

    int squareSize = min(N, M);

    while (squareSize > 1) {
        if (ans(squareSize)) {
            cout << squareSize * squareSize;
            return 0;
        }
        squareSize--;
    }
    cout << 1;
}