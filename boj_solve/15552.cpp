#include <iostream>
using namespace std;
int main(){
    ios::sync_with_stdio(false); 
    cin.tie(NULL);
    int a;
    cin >> a;
    for (int i=0; i<a; i++){
        int a, b;
        cin >> a >> b;
        // cout << a+b << endl; (시간초과남,,왜?)
        cout << a+b << "\n";
    }
}
