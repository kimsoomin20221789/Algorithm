#include <bits/stdc++.h>
using namespace std;

int a; int b;
int c; int d;

int gcd(int x, int y) {
    if (x == 0) {
        return y;
    }
    return gcd(y%x, x);
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> a >> b >> c >> d;

    int x = gcd(a, b);
    int y = gcd(c, d);
    a = a/x;
    b = b/x;
    c = c/y;
    d = d/y;

    long long ansX = a*d+c*b;
    long long ansY = b*d;
    long long ansDivide = gcd(ansX, ansY);
    cout << ansX/ansDivide << " " << ansY/ansDivide;
}