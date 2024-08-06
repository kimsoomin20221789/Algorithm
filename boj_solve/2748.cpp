#include <iostream>
using namespace std;
int N;
int dp[91]; //dp는 저장을 하는 공간! (memorization)


int fib(int a){
    if (dp[a]!=-1) {return dp[a];}
    return dp[a] = fib(a-1) + fib(a-2);
}

int main(){
    cin >> N;
    for (int i=0; i<91; i++){
        dp[i] = -1;
    }   
    dp[0] = 0;
    dp[1] = 1;
    cout << fib(N);
}