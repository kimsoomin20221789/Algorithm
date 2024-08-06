#include <bits/stdc++.h>
using namespace std;

//{0,1,2,3} 의 부분집합
bool isused[4];
void func(int k) {
    if (k==4) {
        cout << "{";
        for (int i=0; i<4; i++) {
            if (isused[i]) {
                cout << i;
            }
        }
        cout << "}\n";
        return;
    }
    func(k+1);
    isused[k] = true;
    func(k+1);
    isused[k] = false;
}

void func2() {
    for (int tmp=0; tmp<16; tmp++) {
        cout << "{";
        int brute = tmp;
        for (int i=0; i<4; i++) {
            if (brute%2 == 1) cout << i;
            brute /= 2;
        }
        cout << "}\n";
    }
}

void func3() {
    for (int tmp=0; tmp<16; tmp++) {
        cout << "{";
        for (int i=0; i<4; i++) {
            if (tmp & (1<<i)) {
                cout << i;
            }
        }
        cout << "}\n"; 
    }
}
int main() {
    // func(2);
    // func2();
    func3();
}