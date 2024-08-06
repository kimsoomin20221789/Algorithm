#include <iostream>
#include <algorithm>
using namespace std;

bool findChecking(int* arr1, int n, int x){
    int target = x;
    bool checking = find(arr1, arr1+n, target) != arr1 + n;
    return checking;
}


int main(){
    int N; cin >> N;
    int arr[N];
    for (int i=0; i<N; i++){
        cin >> arr[i];
    }
    int x; cin >> x;

    sort(arr, arr+N);
    int i=0;
    int cnt = 0;
    while (true){
        if(arr[i]>x-arr[0]){
            break;
        }
        if (findChecking(arr, N, x - arr[i])){
            cnt++;
        }
        i++;
    }

    cout << cnt/2 ;
}