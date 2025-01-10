#include <bits/stdc++.h>
using namespace std;
string explosionString;
string inputString;
vector<char> inputCharVec;
deque<char> explosionCheckDeq;

bool isExplosion() {
    explosionCheckDeq.clear();

    for (int i = explosionString.size()-1 ; i>=0 ; i--) {
        char inputEndChar = inputCharVec.back();
        explosionCheckDeq.push_front(inputEndChar);
        inputCharVec.pop_back();
        if (explosionString[i] != inputEndChar) {
            return false;
        }
    }

    return true;
}

void answer() {
    if (inputCharVec.empty()) {
        cout << "FRULA";
    } else {
        for (char c : inputCharVec) {
            cout << c;
        }
    }
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    cin >> inputString >> explosionString;

    for (char inputChar : inputString) {
        inputCharVec.push_back(inputChar);
        if (inputCharVec.size() >= explosionString.size()) {
            if (!isExplosion()) {
                for (char c : explosionCheckDeq) {
                    inputCharVec.push_back(c);
                }
            }
            
        }
    }

    answer();
}