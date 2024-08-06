#include <bits/stdc++.h>
using namespace std;
int A[100000];
int main(){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n;
    cin >> n;
    for (int i=0; i<n; i++){
        cin >> A[i];
    }
    sort(A , A+n); //벡터라면 sort일때 .begin, .end사용
    int m; 
    cin >> m;
    for (int i=0; i<m; i++){
        int t; cin >> t;
        cout << binary_search(A, A+n , t) << "\n";
    }
}
