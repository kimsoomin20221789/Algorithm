#include <bits/stdc++.h>
using namespace std;

vector<int> v;
int N; 
long long answer;

string decideTrue(int mid) {
    answer = 0;

    
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> N;

    for (int i=0; i<N; i++) {
        int x; cin >> x; v.push_back(x);
    }

    int start = v[0];
    int finish = v[1];
    
    while (start<=finish) {
        int mid = (start + finish) / 2;
        
        if (decideTrue(mid) == "right") {
            start = mid;
        } else if (decideTrue(mid) == "left"){ 
            finish = mid;
        } else {
            cout << answer;
        }
    }
    cout << answer;
}