#include <bits/stdc++.h>
using namespace std;
vector<int> v;
int N; int S; 
int L = 0; int R = 0;
int partSum;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N; cin >> S;

    for (int i=0; i<N; i++) {
        int x; cin >> x; v.push_back(x);
    }

    partSum = v[0];
    int answer = 100000;
    while (R<N) {
        if (partSum < S) {
            R++;
            partSum += v[R];

        } else if (partSum > S) {
            if (L == R) {
                R++;
                partSum += v[R];
            } else {
                partSum -= v[L];
                L++;
            }
        } else {
            answer = min(R-L+1, answer);
            R++;
        }
    }
    
    if (answer == 100000) {
        cout << 0;
    } else {
        cout << answer;
    }
    
}