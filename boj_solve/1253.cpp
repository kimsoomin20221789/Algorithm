#include <bits/stdc++.h>
using namespace std;
int arr[2002];
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N; cin >> N;
    int answer = 0;
    for (int i=0; i<N; i++) {
        cin >> arr[i];
    }

    sort(arr, arr+N);

    for (int k=0; k<N; k++) {
        int l = 0; int r = N-1;
        int sumGoal = arr[k];
        while (l<r) {
            int val = arr[l]+arr[r];
            if (val == sumGoal) {
                if (l!=k && r!=k) {
                    answer++;
                    break;
                } else if (l==k) {
                    l++;
                } else {
                    r--;
                }
            } else if (val < sumGoal) {
                l++;
            } else {
                r--;
            }
        }
    }

    cout << answer;
}