#include <string>
#include <vector>
#include <iostream>
#define ll long long
using namespace std;
// 0:+ , 1:- , 2:x , 3:/ , 4:십일
vector<ll> dp[8];

ll cal(ll x, ll y, int calculatorNum) {
    switch (calculatorNum) {
        case 0 :
            return x+y;
        case 1:
            return x-y;
        case 2:
            return x*y;
        case 3:
            return x/y;
        default:
            return 10*x + y;
    }
}

int solution(int N, int number) {
    int answer = 0;
    return answer;
    
    dp[0].push_back(N);
    
    for (int i=1; i<=8; i++) {
        if (i==8) {
            cout << -1;
            // return -1;
        }
        for (auto x : dp[i-1]) {
            for (int j = 0; j<=4; j++) {
                ll ans = cal(x, N, j);
                if (ans == number) {
                    cout << i;
                    // return i;
                }
                dp[i].push_back(ans);
            }
            
        }
    }
}