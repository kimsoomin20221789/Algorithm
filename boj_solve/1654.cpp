#include <bits/stdc++.h>
using namespace std;
int arr[100000];
int n; int k;
int binarysearch(int target){
    int st = 0;
    int end = arr[n-1];
    while (st<=end){
        long long mid = (st+end)/2;
        int num = 0;
        for (int i=0; i<n; i++){
            num += arr[i] / mid;
        }
        if (num<target){
            st = mid + 1;
        } else if (num > target){
            end = mid - 1;
        }
        else return mid;
    }
    return 0;
}
int main(){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    
    cin >> k >> n;
    for (int i=0; i<k; i++){
        cin >> arr[i];
    }
    sort(arr, arr+n);

   
    cout << binarysearch(k);
}
