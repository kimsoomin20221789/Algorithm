#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n; int k;
    cin >> n >> k;
    int d[k+1];
    d[0] = 0;
    int val[n];
    for (int i=0; i<n; i++){
        cin >> val[i];
    }

    for (int i=1; i<k+1; i++){
        d[i] = 1;
        for (int j=0; j<n; j++){
            if (i>=val[j]){
                d[i] += d[i-val[j]];
            }
        }
        
    }
    
    for (int i=0; i<k+1; i++){
        cout << d[i];
    }
    cout << "#" << d[k];
    
}