#include <bits/stdc++.h>
using namespace std;
int main(){
    int N; cin >> N;
    priority_queue<int, vector<int>, greater<int> > pq;
    for (int i=0; i<N; i++){
        int a; cin >> a; pq.push(a);
    }

    if (N==1){
        cout << 0;
    } else {

        int sum = 0;

        while (true){
            int new_value = 0;
            for (int i=0; i<2; i++){
                int a; a = pq.top(); pq.pop();
                new_value += a;
            }
            sum += new_value;
            if (pq.size() == 0){
                break;
            }
            pq.push(new_value);
        }
    
        cout << sum;
    }
}