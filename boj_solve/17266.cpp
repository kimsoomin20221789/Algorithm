#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int N; int M; cin >> N >> M;

    int answer = -1;
    int pre;
    for (int i=0; i<M; i++) {
        int x; cin >> x;
        if (i==0) {
            answer = max(answer, x-0);
        } 
        if (i==M-1) {
            answer = max(answer, N - x);
        } else {
            int a = (x-pre+1)/2;
            answer = max(a, answer);
        }
        pre = x;
    }

    cout << answer;
}