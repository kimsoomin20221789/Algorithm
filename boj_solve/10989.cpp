#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n; cin >> n;
    int contain[10001] = {0};

    for (int i=0; i<n; i++){
        int index; cin >> index;
        contain[index]++;
    }

    for (int i=0; i<10001; i++){
        if (contain[i] != 0){
            int k = contain[i];
            for (int j = k; j>0; j--){
                cout << i << "\n";
            }
        }
    }
}