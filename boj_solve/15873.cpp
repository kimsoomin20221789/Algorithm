#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    int a;
    int b;
    
    cin >> s;

    if (s.size() == 3) {
        if (s[1] == '0') {
            a = 10;
            b = s[2] - '0';
        } else {
            a = s[0] - '0';
            b = 10;
        }
    } else if (s.size() == 4) {
        a = 10;
        b = 10;
    } else {
        a = s[0] - '0';
        b = s[1] - '0';
    }

    cout << a+b;
}