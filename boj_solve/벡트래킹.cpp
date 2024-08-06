#include <iostream>
#include <vector>
using namespace std;
int n, m;
int f(vector<int> v){
    if (v.size() == m){
        bool flag = true;
        sort(v.begin(), v.end());
        for (int i=1; i<v.size(); i++){
            if (v[i] == v[i-1]) flag = false;
        }
        if (flag){
        cout << "";
        }
        return;
    }
    for (int i=1; i<=n; i++){
        arr[i]=1;
    }
}

//branch&bound
int arr[10];
int main(){

}