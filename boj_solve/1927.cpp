#include <iostream>
#include <queue>
using namespace std;

int main(){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int N; cin >> N;
    int x;
    priority_queue<int, vector<int>, greater<int> > pq1;
    for (int i=0; i<N; i++){
        cin >> x;
        if (x == 0){
            if (pq1.empty()){
                cout << "0" << "\n";
            } else {
                cout << pq1.top() << "\n";
                pq1.pop();
            }
        } else {
            pq1.push(x);
        }
    }
}