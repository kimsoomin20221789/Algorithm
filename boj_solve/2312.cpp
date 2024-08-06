#include <iostream>
#include <map>
using namespace std;

int main(){
    int N; cin >> N;
    
    for (int j=0; j<N; j++){
        map<int, int> m;
        int K; cin >> K;
        int x = K;
        for (int i=2; i*i<=K; ++i){
            while (x%i == 0){
                x = x / i;
                 m[i]++;
            }
        }
        if (x != 1){
            m[x] ++;
        }
        for(map<int, int>::iterator it=m.begin(); it!=m.end(); ++it){
            cout << it->first << " " << it->second << " " << endl;
        }
    }


}