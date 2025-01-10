#include <bits/stdc++.h>
using namespace std;
string explosionString;
string inputString; 

bool isExplosion(int startIndex) {
    for (int i = 0; i < explosionString.size(); i++) {
        if (explosionString[i] != inputString[i+startIndex]) {
            return false;
        }
    }
    return true;
}

void answer() {
    if (inputString.empty()) {
        cout << "FRULA";
    } else {
        cout << inputString;
    }
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    cin >> inputString;
    cin >> explosionString;

    bool escapeWhile = false;
    while (!inputString.empty() && !escapeWhile) {
        for (int i=0; i<inputString.size(); i++) {
            if (isExplosion(i)) {
                inputString.erase(i, explosionString.size());
                break;
            }
            if (i==inputString.size()-1) {escapeWhile = true;}
        }
    }

    answer();
}