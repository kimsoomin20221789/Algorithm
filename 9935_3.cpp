#include <bits/stdc++.h>
using namespace std;
string inputString; 
string explosionString;
string checkedString;

bool hasExplosion() {
    return explosionString == checkedString.substr(checkedString.size()-  explosionString.size());
}

bool isRightSize() {
    return checkedString.size() >= explosionString.size();
}

void deleteExplosion() {
    for (char c : inputString) {
        checkedString += c;
        if (!isRightSize()) {continue;}

        if (hasExplosion()) {
            checkedString.erase(checkedString.size() - explosionString.size());
        }
    }
}

void answer() {
    if (checkedString.empty()) {
        cout << "FRULA";
    } else {
        cout << checkedString;
    }
}


int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    cin >> inputString >> explosionString;

    deleteExplosion();
    answer();

}