#include <bits/stdc++.h>
using namespace std;
using ll = long long;
vector<ll> v;
int distance(int x){
    int sum = 0;
    for (int i=0; i<v.size(); i++){
        sum += abs(v[i] - v[x]);
    }
    return sum;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n; cin >> n;
    for (int i=0; i<n; i++){
        int k; cin >> k;
        v.push_back(k);
    }
    sort(v.begin(), v.end());
    if (n%2 == 1){
        cout << v[(n+1)/2-1];
        return 0;
    } else {
        int a = n/2;
        int b = a+1;
        if (distance(a-1) <= distance(b-1)){
            cout << v[a-1];
        } else {
            cout << v[b-1];
        }
    }
}