#include <bits/stdc++.h>
using namespace std;
vector<int> v;
int main () {
    cin.tie(0);
    ios::sync_with_stdio(0);
    int N; int X;
    cin >> N >> X;
    vector<int> v;
    for (int i=0; i<N; i++) {
        int input; cin >> input;
        v.push_back(input);
        if (X > input) {
            cout << input << " ";
        }
    }
}