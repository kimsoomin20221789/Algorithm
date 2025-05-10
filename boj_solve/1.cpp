#include <bits/stdc++.h>
using namespace std;
int main() {
    bool x = "911" < "1111";
    cout << x << "\n" << "\n";

    vector<string> v = {"91", "9122", "76", "1234"};

    sort(v.begin(), v.end());
    for (auto i : v) {
        cout << i << "\n";
    }

}