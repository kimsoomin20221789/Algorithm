#include <iostream>
using namespace std;
int main(){
    long long N; long long P; 
    cin >> N >> P;
    long long cnt=1;
    for (long long i=N; i>=1; i--){
        cnt *= i;
    }
    long long k = cnt%P;
    cout << k;
}