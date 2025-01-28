#include <bits/stdc++.h>
using namespace std;
int arr[200003];
typedef long long ll;
map<int, ll> m;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n; int k; cin >> n >> k;
    ll result = 0;

    for (int i=1; i<=n; i++) {
        cin >> arr[i];
        arr[i] += arr[i - 1]; // arr[i]는 0~i까지의 합.
        m[arr[i]]++;
        if (arr[i] == k) {
            result++;
        }
    }

    // arr[j] - arr[i] = k 는 i+1~j까지 부분집합
    for (int i=1; i<=n; i++) {
        m[arr[i]]--;
        result += m[arr[i] + k];
    }


    cout << result << '\n';


}