#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int gcd(int a, int b) {
    if (b==0) {
        return a;
    }
    return gcd(b, a%b);
}

ll backTracking(deque<int> dq2) {
    if (dq2.size() <= 3) {
        ll total = 0;
        for (auto i : dq2) {
            total += i;
        }
        return total;
    }

    int leftCnt = dq2.size() / 2;

    deque<int> newDeque(dq2.begin() + leftCnt, dq2.end());
    deque<int> newDeque2(dq2.begin(), dq2.begin() + leftCnt);
    ll rightRemainResult = backTracking(newDeque);
    ll leftRemainResult = backTracking(newDeque2);
    
    //왼쪽 최대공약수 구하기
    int leftCurrentGcd = dq2.front();
    for (int i=0; i<leftCnt; i++) {
        int k = dq2.front();
        leftCurrentGcd = gcd(leftCurrentGcd, k);
        dq2.pop_front();
    }
    
    // ll rightRemainResult = backTracking(newDeque);

    int rightCurrentGcd = dq2.front();
    while (!dq2.empty()) {
        int k = dq2.front();
        rightCurrentGcd = gcd(rightCurrentGcd, k);
        dq2.pop_front();
    }
    
    

    return max(leftCurrentGcd+rightRemainResult, rightCurrentGcd + leftRemainResult);
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N; cin >> N;
    deque<int> dq;
    for (int i=0; i<N; i++) {
        int a; cin >> a;
        dq.push_back(a);
    }

    


    cout << backTracking(dq);
}