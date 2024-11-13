#include <bits/stdc++.h>
using namespace std;
int total;
int arr[11][11];
int visited[11];
void backTracking(int arr[][11], int cnt, int visited[], int sum) {
    if (cnt == 11) {
        total = max(total, sum);
        return;
    }
    for (int i=0; i<11; i++) {
        if (!visited[i] && arr[cnt][i]) {
            visited[i] = 1;
            sum += arr[cnt][i];
            backTracking(arr, cnt+1, visited, sum);
            sum -= arr[cnt][i];
            visited[i] = 0;
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int N; cin >> N;
    for (int i=0; i<N; i++) {
        total = 0;
        for (int a = 0; a < 11; a++) {
            for (int b = 0; b < 11; b++) {
                cin >> arr[a][b];
            }
        }
        backTracking(arr, 0, visited, 0);
        cout << total << "\n";
    }
}