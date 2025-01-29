#include <bits/stdc++.h>
using namespace std;

class Median {
    private:
        priority_queue<int> maxHeap;
        priority_queue<int, vector<int>, greater<>> minHeap;
    public:
        void insert(int x) {
            if (maxHeap.empty() || x <= maxHeap.top()) {
                maxHeap.push(x);
            } else {
                minHeap.push(x);
            }

            if (maxHeap.size() > minHeap.size() + 1) {
                minHeap.push(maxHeap.top());
                maxHeap.pop();
            } else if (minHeap.size() > maxHeap.size()) {
                maxHeap.push(minHeap.top());
                minHeap.pop();
            }
        }
        int query() {
            return maxHeap.top();
        }
};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int N; cin >> N;
    Median central = Median();
    for (int i=0; i<N; i++) {
        int x; cin >> x;
        central.insert(x);
        cout << central.query() << "\n";
    }
}