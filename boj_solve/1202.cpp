#include <bits/stdc++.h>
using namespace std;

pair<int, int> jewel[300003];
multiset<int> bag;

int main(){
    ios::sync_with_stdio(false); 
    cin.tie(NULL);
    int n; int k;
    cin >> n >> k;

    //자료 다 map에다가 담기 (최대가격 순으로)
    for (int i=0; i<n; i++){
        cin >> jewel[i].second >> jewel[i].first;
    }
    sort(jewel, jewel+n);
    //가방 자료구조 = ??배열로 하면 찾는데 시간 오래걸리니까  
    for (int i=0; i<k; i++){
        int c;
        cin >> c;
        bag.insert(c);
    }
    long long ans = 0;
    //보석 가장 큰거부터 담을 가방이 있고 그것을 작은 가방으로 담음.
    for (int i=n-1; i>=0; i--){
        int m, v;
        tie(v, m) = jewel[i];
        //multiset을 써야하는 이유!!!!
        auto it = bag.lower_bound(m);
        if (it == bag.end()) continue;
        ans += v;
        bag.erase(it);
    }
    cout << ans;

}