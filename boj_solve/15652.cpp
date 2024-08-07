#include <bits/stdc++.h>
using namespace std;
int N; int M;
int arr[10];

void func(int k) {
    if (k==M) {
        for (int i=0; i<M; i++) {
            cout << arr[i] << " ";
        }
        cout << "\n";
        return;
    }

    for (int i=1; i<=N; i++) {
        if (k>=1 && arr[k-1] > i) {continue;}
        arr[k] = i;
        func(k+1);
    }
}


int main() {
    cin >> N >> M;
    func(0);
}