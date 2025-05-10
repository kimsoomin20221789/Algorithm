#include <bits/stdc++.h>
using namespace std;

vector<int> v;
unordered_map<int, int> memo;

int backTracking(int curIndex) {
    if (curIndex == v.size()) {
        return 1;
    }

    if (memo.count(curIndex)) {  // 이미 계산된 값이 있으면 그 값을 반환
        return memo[curIndex];
    }
    
    int curIndexCnt = 0;
    if (curIndex <= v.size()-2 && v[curIndex] != 0 
        && v[curIndex]*10 + v[curIndex+1] <= 34) {
        curIndexCnt += backTracking(curIndex + 2);
    }

    if (v[curIndex]!=0) {
        curIndexCnt += backTracking(curIndex + 1);
    }
    memo[curIndex] = curIndexCnt;  // 계산된 값을 메모
    return curIndexCnt;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    string s; cin >> s;

    for (auto i : s) {
        v.push_back(i - '0');
    }


    if (!v.empty()) {
        cout << backTracking(0);
    } else {
        cout << 0;
    }
}
