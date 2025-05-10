#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> v; 

bool comp(vector<int>& a, vector<int>& b) {
    if (a[0] == b[0]) {return a[1] > b[1];}
    return a[0] > b[0];
}

long long answer;
int N; 
vector<int> tracking;

void backTracking(int cnt, long long total, int lastWeight, vector<int>& road) {
    if (cnt==N) {
        if (total > answer) {
            answer = total;
            tracking = road;
        }
        return;
    }
    if (v[cnt][1] > lastWeight) { 
        backTracking(cnt+1, total, lastWeight, road);
        
    } else {
        backTracking(cnt+1, total, lastWeight, road);
        road.push_back(v[cnt][3]);
        backTracking(cnt+1, total+v[cnt][2], v[cnt][1], road);
        road.pop_back();
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> N;
    
    for (int i=0; i<N; i++) {
        int a; int b; int c;
        cin >> a >> b >> c;

        v.push_back({a,c, b, i+1});
    }

    sort(v.begin(), v.end(), comp);
    vector<int> v1 = {};
    backTracking(0, 0, 10003, v1);

    cout << tracking.size() << "\n";
    reverse(tracking.begin(), tracking.end());
    for (auto i : tracking) {
        cout << i << "\n";
    }
}