#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll minAnswer = INFINITY;
ll maxAnswer = -INFINITY;
vector<int> v;
vector<int> cal;
int N;
void backTracking(int cnt, vector<int> cal, ll sum) {
    if (cnt == N) {
        minAnswer = min(minAnswer, sum);
        maxAnswer = max(maxAnswer, sum);
        return;
    }

    for (int i=0; i<4; i++) {
        if (cal[i] > 0) {
            cal[i]--;
            if (i==0) {
                backTracking(cnt+1, cal, sum + v[cnt]);
            } else if (i==1) {
                backTracking(cnt+1, cal, sum - v[cnt]);
            } else if (i==2) {
                backTracking(cnt+1, cal, sum * v[cnt]);
            } else if (i==3) {
                backTracking(cnt+1, cal, sum / v[cnt]);
            }
            cal[i]++;
        }
    }
}

int main() {
    cin >> N;
    for (int i=0; i<N; i++){
        int a; cin >> a; v.push_back(a);
    }

    for (int i=0; i<4; i++) {
        int a; cin >> a;
        cal.push_back(a);
    }

    backTracking(1, cal, v[0]);
    cout << maxAnswer << "\n" << minAnswer;
}