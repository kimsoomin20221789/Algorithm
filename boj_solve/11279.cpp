#include <iostream>
#include <queue>
using namespace std;


int main(){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    priority_queue<int> pq1;
    int N;
    cin >> N;
    int x;
    for (int i=0; i<N; i++) {
        cin >> x;
        if (x == 0){
            if (pq1.empty() == true){
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