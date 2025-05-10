#include <bits/stdc++.h>
using namespace std;

map<char, int> m;
int answer;
int len;

void backTracking(int cnt, char pre) {
    if (cnt > len) {
        answer++; return;
    }
    for (auto i : m) {
        if (i.second <= 0) {continue;} 
        if (i.first == pre) {continue;}
        m[i.first]--;
        backTracking(cnt+1, i.first);
        m[i.first]++;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    string s; cin >> s;
    len = s.size();

    for (auto c : s) {
        m[c]++;
    }

    backTracking(1, 'A');

    cout << answer;
}