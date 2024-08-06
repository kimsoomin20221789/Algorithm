#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(0);
	cin.tie(0);
    int x; cin >> x;
    queue<int> Q;
    Q.push(1);
    int sum = 0;
    int y = 1;
    while (!Q.empty()){
        for (int i=0; i<y; i++){
            int a = Q.front();
            Q.pop();
            if (x == a*2 || x == a*3 || x == a+1){
                cout << sum + 1;
                return 0;
            }
            Q.push(a * 2);
            Q.push(a*3);
            Q.push(a+1);
        }
        y *= 3;
        sum += 1;
    }
}