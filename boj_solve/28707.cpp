#include <bits/stdc++.h>
using namespace std;
int N = 10; // 배열의 사이즈
int ans[10];
vector<pair<int, int> > val[10];

bool checkingSort(int arr[]) {
    for (int i=0; i<N-1; i++) {
        int cur = arr[i];
        int nxt = arr[i+1];
        if (cur > nxt) return false;
    }
    return true;
}

int main() {
    cin >> N;
    for (int i=0; i<N; i++) {
        cin >> ans[i];
    }

    int M; cin >> M;
    for (int i=0; i<M; i++) {
        int a; int b; int c;
        val[a].push_back({b, c});
        val[b].push_back({a, c});
    }

    
}
