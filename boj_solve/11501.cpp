#include <iostream>
#include <vector>
using namespace std;


int main(){
    int T;
    cin >> T;
    
    for (int i=0; i<T; i++){

        int N; cin >> N;
        int v[N];
        int v1[N];

        for (int j=0; j<N; j++){
            int a;
            cin >> a; 
            v[j] = a;
        }
        int max = 0;
        
        for (int k=N-1; k>-1; k--){
            if(v[k] > max){
                max = v[k];
            }
            v1[k] = max;
        }
        long long total = 0;
    
        for (int m=0; m<N; m++){
            int sub = v1[m]-v[m];
            if (sub < 0){
                sub = 0;
            }
            total += sub;
        }
        cout << total << "\n";



    }    
}