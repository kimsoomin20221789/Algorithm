#include <iostream>
#include <vector>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    cout.tie(NULL);
    // vector<int> v1;
    int N;
    cin >> N;

    // for (int i=0; i<N; i++){
    //     v1.push_back(i+1);
    // }
    int answer = 0;
    int start = 1;
    int end = 1;
    int partSum = 0;

    while (end <= N+1 && start <= N+1){
        if (partSum <= N){
            partSum += end++;
        } else {
            partSum -= start++;
        }

        if (partSum == N){
            answer ++;
        }
    }
    cout << answer;

}