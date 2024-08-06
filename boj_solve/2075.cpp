#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
	cin.tie(0);
    priority_queue<int, vector<int>, greater<int> > pq;
    int N; cin>>N;
    for (int i=0; i<N; i++){
        int x; cin>>x;
        pq.push(x);
    }

    for (int i=0; i<N*(N-1); i++){
        int x; cin>>x;
        pq.push(x);
        pq.pop();
    }
    
    cout << pq.top();
}

//블로그보면서 set이 아닌 priority_queue쓰는이유 시간, 메모리 복잡도 관점