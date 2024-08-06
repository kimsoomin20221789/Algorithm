//2분탐색
//전제 조건 : 정렬이 돼있어야됨
//upperbound , lowerbound (갯수 찾고싶을때 = 밑에 코드)
// while(M--){
//     int a; cin>>a;
//     auto it1 = lower_bound(v.begin(), v.end(),a);
//     auto it2 = upper_bount(v.begin(), v.end(), a);
//     cout << it2 - it1 << endl;
// }


#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector <int> v;
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int N; cin >> N;
    for (int i =0; i<N; i++){
        int a; cin>>a; v.push_back(a);
    }
    sort(v.begin(), v.end());
    int M; cin >> M;
    bool binary_search()
}