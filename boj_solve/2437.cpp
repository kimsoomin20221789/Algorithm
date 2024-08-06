#include <bits/stdc++.h>
using namespace std;
using ll = long long;
vector<int> v;

int main(){
    int n; cin >> n;
    int sum = 0;
    for (int i=0; i<n; i++){
        int a;
        cin >> a;
        v.push_back(a);
    }

    sort(v.begin(), v.end());
    for (int i=0; i<v.size(); i++){
        if (v[i] > sum+1){
            cout << sum + 1;
            return 0;
        }
        sum += v[i];
    }
    cout << sum+1;

}