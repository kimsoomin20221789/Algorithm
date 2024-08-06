#include <bits/stdc++.h>
using namespace std;

void fib(int n, int start, int dest) {
    if (n==1) {
        cout << start << ' ' << dest << '\n';
        return;
    }
    fib(n-1, start, 6-start-dest);
    cout << start << ' ' << dest << '\n';
    fib(n-1, 6-start-dest, dest);
}

int main() {
    int N; cin >> N;
    cout << (1<<N) - 1 << '\n';
    fib(N, 1, 3);
}