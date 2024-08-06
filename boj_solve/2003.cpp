#include <iostream>
using namespace std;
int main(){
    int N; int M; cin >> N >> M;
    int a[N];
    int pivot1 = 0;
    int pivot2 = 0;
    int answer = 0;
    int partSum = 0;
    for (int i=0; i<N; i++){
        cin >> a[i];
    }

    while (pivot2 <= N){
        if (partSum < M){
            partSum += a[pivot2++];
        } else {
            if (partSum == M){
                answer++;
            }
            partSum -= a[pivot1++];
        }
        
    }

    cout << answer;

}