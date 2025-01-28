#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N; cin >> N;
    queue<int> q; 
    for (int i=1; i<=N; i++) {
        q.push(i);
    }
    vector<int> isDeletedVector;
    bool isDeleted = true;
    while (q.size() != 1) {
        if (isDeleted) {
            int x = q.front();
            q.pop();
            isDeletedVector.push_back(x);
            isDeleted = false;
        } else {
            int x = q.front();
            q.pop();
            q.push(x);
            isDeleted = true;
        }
    }

    for (auto i : isDeletedVector) {
        cout <<  i << " ";
    }
    cout << q.front();
}