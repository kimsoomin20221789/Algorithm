#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N; int M; cin >> N >> M;

    vector<long long> v;
    while(N--) {
        long long x; cin >> x;
        v.push_back(x);
    }

    sort(v.begin(), v.end());

    long long target = M;

    int st = 0;
    int end = v[v.size()-1];
    int answer = 0;
    while (st<=end) {
        int pivot = (st + end) / 2 ;
        int pivot1 = pivot+1;

        long long pivotSum = 0;
        long long pivot1Sum = 0;

        for (auto i : v) {
            if (i - pivot > 0) {
                pivotSum += i-pivot;
            }

            if (i - pivot1 > 0) {
                pivot1Sum += i-pivot1;
            }
        }

        if (pivotSum >= target && pivot1Sum < target) {
            answer = pivot;
            break;
        } else if (pivotSum >= target && pivot1Sum >= target) {
            st = pivot;
        } else {
            end = pivot;
        }
    }
    cout << answer;
}