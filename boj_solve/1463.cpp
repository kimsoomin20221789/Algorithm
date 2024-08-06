#include <bits/stdc++.h>
using namespace std;

int D[1000000];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int x;
    cin >> x;
    D[1] = 0;
    for (int i = 2; i <= x; i++){
        D[i] = D[i-1] + 1;
        if (i%3 == 0) {D[i] = min(D[i], D[i/3]+1);}
        if (i%2 == 0) {D[i] = min(D[i], D[i/2]+1);}
    }
    cout << D[x];
}