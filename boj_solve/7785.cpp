#include <iostream>
#include <set>
using namespace std;

int main(){
    int N; cin>>N;
    //???
    set<int> s;
    int a;
    int b;
    /////
    for (int i=0; i<N; i++){
        cin >> a >> b;
        if (b == "enter"){
            s.insert(a);
        } else {
            if (s.find(a) != s.end()){
                s.erase(a);
            }
        }
    }
}