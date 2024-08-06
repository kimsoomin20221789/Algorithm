#include <bits/stdc++.h>
using namespace std;

int main(){
    int n; int k; cin>>n; cin>>k;
    int w[n];
    int v[k];
    int T[n][k+1];
    for (int i=0; i<n; i++){
        cin >> w[i];
        cin >> v[i];
    }

    for (int j=0; j<k+1; j++){
        if (w[0] > j){
            T[0][j] = 0;
        } else {
            T[0][j] = v[0];
        }
    }


    for (int i=1; i<n; i++){
        for (int j=0; j<k+1; j++){
            if (w[i] > j){
                T[i][j] = T[i-1][j];
            } else {
                T[i][j] = max(T[i-1][j], v[i] + T[i-1][j-w[i]]);
            }
        }
    }
    cout << T[n-1][k];
}