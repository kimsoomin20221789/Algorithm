#include <bits/stdc++.h>
using namespace std;
using ll = long long;
vector<ll> v;

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n; cin >> n;
    for (int i=0; i<n; i++){
        ll k;
        cin >> k;
        v.push_back(k);
    }
    sort(v.begin(), v.end());
    ll max_value = v[0];
    int counting = 1;
    int max_counting = 0;
    for (int i=1; i<n; i++){
        if (v[i] != v[i-1]){
            if (max_counting <= counting){
                if (max_counting == counting){
                    max_value = min(max_value, v[i-1]);
                    max_counting = counting;
                    counting = 1;
                    continue;
                }
                max_value = v[i-1];
                max_counting = counting;
                counting = 1;
                continue;
            } else {
                counting = 1;
                continue;
            }
        } else {
            counting++;
            continue;
        }
    }
    if (max_counting <= counting){
        if (max_counting == counting){
            max_value = min(max_value, v[n-1]);
        } else {
            max_value = v[n-1];
        }
    }
    cout << max_value;
}