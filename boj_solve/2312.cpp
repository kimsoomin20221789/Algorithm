#include <bits/stdc++.h>
using namespace std;

int main(){
    int N; cin >> N;
    map<int, int> m;
    m[4] = 6;
    m[2]++;
    // for (int j=0; j<N; j++){
    //     map<int, int> m;
    //     int K; cin >> K;
    //     int x = K;
    //     for (int i=2; i*i<=K; ++i){
    //         while (x%i == 0){
    //             x = x / i;
    //              m[i]++;
    //         }
    //     }
    //     if (x != 1){
    //         m[x] ++;
    //     }
        for(auto it=m.begin(); it!=m.end(); ++it){
            cout << it->first << " " << it->second << " " << endl;
            cout << (*it).first << " " << (*it).second << " " << endl;
        }

        for(auto it : m){
            cout << it.first << " " << it.second << " " << endl;
        }
    // }
    vector<pair<int, int>> v;

    for(auto it=v.begin(); it!=v.end(); ++it){
        cout << it->first << " " << it->second << " " << endl;
        cout << (*it).first << " " << (*it).second << " " << endl;
    }

    for(auto it : v){
        cout << it.first << " " << it.second << " " << endl;
    }

}