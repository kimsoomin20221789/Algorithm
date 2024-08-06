#include <bits/stdc++.h>
using namespace std;
void test(){
    priority_queue<int, vector<int> ,greater<int> > pq;
    int n; int m;
    cin >> n >> m;
    for (int i=0;i<n;i++){
        int a;
        cin >> a;
        pq.push(a);
    }
   
    for (int i=0; i<m; i++){
        int x = pq.top();
        pq.pop();
        int y = pq.top();
        pq.pop();
        pq.push(x+y);
        pq.push(x+y);
    }
    int sum = 0;
    while (!pq.empty()){
        sum += pq.top();
        pq.pop();
    }
    cout << sum;
}

int main(){
    ios::sync_with_stdio(0);
	cin.tie(0);
    test();

}
//벡터나 다른걸로 풀어서 정렬시키는 거랑 시간복잡도 비교해보기