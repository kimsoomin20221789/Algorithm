#include <bits/stdc++.h>
using namespace std;
int d[2000];
int a[2000];
int main(){
    int n; cin >> n;
    for (int i=0; i<n; i++){
        cin >> a[i];
    }
    for(int i = 0; i < n; i++) {
    d[i] = 1;
    }
    for (int i=1; i<n; i++){
        for (int j=0; j<i; j++){
            if (a[j]>a[i]){
                d[i] += 1;
                // d[i] = max(d[j]+1 , d[i]);
            }
        }
    }
    cout << n - *(max_element(d, d+n));

}