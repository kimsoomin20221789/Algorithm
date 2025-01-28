#include <iostream>
using namespace std;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    long long N; long long P; 
    cin >> N >> P;
    long long cnt=1;
    for (long long i=N; i>=1; i--){
        cnt = (cnt%P * i%P) % P;
    }
    cout << cnt;
}