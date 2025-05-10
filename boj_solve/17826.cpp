#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int arr[50];
    for (int i=0; i<50; i++) {
        cin >> arr[i];
    }

    int hongik; cin >> hongik;
    int answer = 0;
    for (int i=0; i<50; i++) {
        if (arr[i] == hongik) {
            answer = i+1;
            break;
        }
    }

    if (answer <=5) {
        cout << "A+";
    } else if (answer <=15) {
        cout << "A0";
    } else if (answer <=30) {
        cout << "B+";
    } else if (answer <= 35) {
        cout << "B0";
    } else if (answer <= 45) {
        cout << "C+";
    } else if (answer <= 48) {
        cout << "C0";
    } else {
        cout << "F";
    }
}