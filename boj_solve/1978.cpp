#include <iostream>
using namespace std;
const int MAX_N = 1000;
bool isErased[MAX_N+1];
int main(){
    int N; cin >> N;

    isErased[0] = true;
    isErased[1] = true;
    for(int p=2; p*p <=MAX_N+1; ++p){
        if(isErased[p]) continue;
        for(int j=p*p; j<=MAX_N+1; j+=p){
            isErased[j]=true;
        }
    }
    int x;
    int cnt=0;
    for (int i=0; i<N; i++){
        cin >> x;
        if (isErased[x]==false){
            cnt++;
        }
    }
    cout << cnt;
}