#include <bits/stdc++.h>
using namespace std;
priority_queue<int, vector<int> > max_pq;
priority_queue<int, vector<int>, greater<int> > min_pq;
map<int, int> cnt;
// int small_index(priority_queue<int, vector<int> > pq1){
//     int n = pq1.size();
//     int small_index = 0;
//     while (small_index < n){
//         int l = 2*small_index+1;
//         int r = 2*small_index*2;
//         if (pq1.at(l) < pq1.at(r)){

//         }
//     }
// }
int main(){
    int T; cin >> T;
    for (int i = 0; i<T; i++){
        int k; cin >> k;
        for (int j=0; j<k; j++){
            char M; int N;
            cin >> M; cin >> N;
            if (M == 'D'){
                if (max_pq.size()==0 || min_pq.size()==0){
                    continue;
                }
                if (N == 1){
                    while (true){
                        int x = max_pq.top();
                        if (!(cnt[x] == 0)){
                            max_pq.pop();
                            cnt[x]--;
                            break;
                        }
                        max_pq.pop();
                    }
                } else {
                    while (true){
                        int x = min_pq.top();
                        if (!(cnt[x] == 0 )){
                            min_pq.pop();
                            cnt[x]--;
                            break;
                        }
                        min_pq.pop();
                    }
                }
            } else {
                max_pq.push(N);
                min_pq.push(N);
                cnt[N] ++;

            }
        }
        if (min_pq.empty() || max_pq.empty()){
            cout << "Empty" << "\n";
        } else {
            cout << max_pq.top() << " "  << min_pq.top();
        }
    }
}