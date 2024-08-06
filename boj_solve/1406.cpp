#include <bits/stdc++.h>
using namespace std;
auto cur = l.end();
list<char> l;

void L() {
    if (cur == 0) {return;}
    cur -= 1;
}

void D() {
    if (cur == 0) {return;}
    cur -= 1;
    cur = l.erase(cur);
}

void B() {

}

void P(char s) {

}
int main() {
    string s; cin >> s;

    for (auto c : s){ l.push_back(c);}

    int n; cin >> n;
    cur = s.length();
    for (int i=0 ;i<n; i++){

    }
}