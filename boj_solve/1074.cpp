#include <bits/stdc++.h>
using namespace std;
int N; int r; int c;

int func(int N, int r, int c) {
    if ((r == 1 || r == 0) && (c == 1 || c == 0)) {
        if ((r,c) == (1,0)) {
            return 2;
        } else if ((r,c) == (0,0)) {
            return 0;
        } else if ((r,c) == (0,1)) {
            return 1;
        } else if ((r,c) == (1,1)) {
            return 3;
        }
    }

    func()
}

int main() {
    cin >> N >> r >> c;
    func(N, r, c);
}