#include <bits/stdc++.h>
using namespace std;

template <typename T>
T max_of_four(T a, T b, T c, T d) {
    return std::max(std::max(std::max(a, b), c), d);
}
int main(){
    int n; cin >> n;
    int arr[n+1];
    int d[n+1];
    for (int i=1; i<=n; i++){
        cin >> arr[i];
    }
   d[0] = 0;
    d[1] = arr[1];
    d[2] = arr[1] + arr[2];
    for(int i=3; i<=n; i++){
        d[i] = max({d[i-3]+arr[i-1]+arr[i], d[i-2]+arr[i], d[i-1]});
    }
    printf("%d\n", d[n]);
}