#include <iostream>
using namespace std;


int main(){
    int min;
    int max;
    cin >> min >> max;
    int size1 = max-min;

    bool isErased[size1];
    int cnt = 0;
    if (min == 1){
        isErased[0] = true;
    }
    for(int p=min; p*p <=max; ++p){
        if(isErased[p-min]) continue;
        for(int j=p*p; j<=max; j+=p){
            isErased[j-min]=true;
            cout << j-min+1 << "&&";
            cnt ++;
        }
    }
    cout << cnt;
}