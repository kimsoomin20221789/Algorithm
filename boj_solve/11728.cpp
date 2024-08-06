#include <iostream>
#include <vector>
using namespace std;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    int N; int M;
    cin >> N >> M;
    int ar1[N];
    int ar2[M];
    vector<int> v1;
    for (int i=0; i<N; i++){
        cin >> ar1[i];
    }

    for (int j=0; j<M; j++){
        cin >> ar2[j];
    }

    int first = 0;
    int second = 0;
    while ((first < N) && (second < M)){
        if (ar1[first]<= ar2[second]){
            v1.push_back(ar1[first++]);
        } else {
            v1.push_back(ar2[second++]);
        }
    }

    while (first < N){
        v1.push_back(ar1[first++]);
    }
    while (second < M){
        v1.push_back(ar2[second++]);
    }

    for (int k = 0; k<v1.size(); k++){
        cout << v1[k] << " ";
    }
}