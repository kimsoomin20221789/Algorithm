#include <iostream>
#include <vector>
using namespace std;
int count = 0;
int v[30001] = {0};
int main(){
    int N; int d; int k; int c;
    cin >> N >> d >> k >> c;
    cout << v[0];
    int start = 0;
    int end = k-1;
    int cnt = 1;
    int answer = 0;
    int val;
    for (int i=0; i<N; i++){
        if (cnt > k){
            cin >> val;
            continue;
        }
        cin >> val;
        v[val]++;
        if (v[val]>=2){
            cnt++;
            continue;
        }
        answer++;
        cnt ++;
    }

    int partSum = 0;
    
    while (start <= N-1){
        start++; end++;
        if (end==N){
            end = 0;
        } 
    }
}