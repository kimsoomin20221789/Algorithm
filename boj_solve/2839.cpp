#include <bits/stdc++.h>
using namespace std;

int main() {
    int N; cin >> N;
    int fiveMax = 0;

    int fiveVal = -1;
    int threeVal = -1;

    fiveMax = N / 5;

    for (int i=fiveMax; i>=0; i--) {
        int rem = N - i*5;
        int threeMax = rem / 3;
        for (int j=threeMax; j>=0; j--) {
            if (rem - j*3 == 0) {
                fiveVal = i;
                threeVal = j;
                break;
            }
        }
        if (fiveVal != -1) {
            break;
        }
    }

    if (fiveVal == -1) {
        cout << -1;
    } else {
        cout << fiveVal + threeVal;
    }
}