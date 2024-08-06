#include <bits/stdc++.h>
using namespace std;

//스택 구현
const int MX = 1000005;
int dat[MX];
int pos = 0;

void push(int x){
    dat[pos] = x;
    pos++;
}

void pop(){
    pos--;
}

int top(){
    return dat[pos-1];
}

void test(){
  push(5); push(4); push(3);
  cout << top() << '\n'; // 3
  pop(); pop();
  cout << top() << '\n'; // 5
  push(10); push(12);
  cout << top() << '\n'; // 12
  pop();
  cout << top() << '\n'; // 10
}

int main(void) {
	test();
}

//STL 스택
//push, pop, top
//empty, size
//비어있을때 pop이나 top 호출 못함. -> 런타임 에러
int main() {
    stack<int> s;
    s.push(10);
    s.push(20);
    s.push(30);
    cout << s.size() << '\n';
    if (s.empty()) cout << "S is empty\n";
    else cout << "s is not empty\n";
    s.pop();
    cout << s.top() << '\n';
    s.pop();
    cout << s.top() << '\n';
    s.pop();
    if (s.empty()) {
        cout << "s is empty\n";
    }
    cout << s.top() << '\n' // 런타임 에러 발생
}