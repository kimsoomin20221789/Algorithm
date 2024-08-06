#include <iostream>
#include <string>
#include <stack>
#include <vector>
using namespace std;
int semiTotal;
stack<char> st1;
// void stackClear(stack<char> s){
//     while (!s.empty()){
//         s.pop();
//     }
// }
//이거 쓰면 안먹는 이유 알려줄사람~?~?~?

void makeSemiTotal(stack<char> s){
    int mul = 1;
    int number = 0;
    while (!s.empty()){
        char x = s.top();
        s.pop();
        if (x == '+'){
            
            semiTotal += number;
            
            number = 0;
            mul = 1;
            continue;
        }
        number += int(x-48) * mul;
        mul *= 10;
    }
    
    semiTotal += number;
    
}

int main(){
    
    string s; cin >> s;
    int total = 0;
    semiTotal = 0;
    // stack<char> st1;
    vector<int> v;

    
    for (int i=0; i<s.length(); i++){
        if (s[i] == '-'){
            //semitotal 만들어주기
            makeSemiTotal(st1);
            //===================
            v.push_back(semiTotal);
            semiTotal = 0;
            // stackClear(st1);
            while (!st1.empty()){
                st1.pop();
            }
            continue;

        }
        st1.push(s[i]);
    }
    if (!st1.empty()){
        makeSemiTotal(st1);
        v.push_back(semiTotal);
        
    }

    total += v[0];
    
    for (int i=1; i<v.size(); i++){
        total -= v[i];
        
    }
    
    cout << total;

}