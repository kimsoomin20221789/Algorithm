#include <iostream>
#include <set>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n; cin >> n;
    string s;
    set<int> S;
    for (int i=0; i<n; i++) {
        cin >> s;
        if (s == "add") {
            int element; cin >> element;
            S.insert(element);
        } else if (s == "check") {
            int element; cin >> element;
            if (S.find(element)!=S.end()) {
                cout << 1 << "\n";
            } else {cout << 0 << "\n";}
        } else if (s == "remove") {
            int element; cin >> element;
            if (S.find(element)!=S.end()) {
                S.erase(element);
            }
        } else if (s == "toggle") {
            int element; cin >> element;
            if (S.find(element)==S.end()) {
                S.insert(element);
            } else {S.erase(element);};
        } else if (s == "all") {
            S = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20};
        } else if (s == "empty") {
            S = {};
        }
    }
}