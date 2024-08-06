#include <bits/stdc++.h>
using namespace std;

void set_example(){
    set<int> s;
    s.insert(-10);
    s.insert(100);
    s.insert(150);
    s.insert(200);
    s.insert(-10); //중복 허용하지 않음.
    cout << s.erase(150) << "\n"; 
    //파라미터 iterator : 제거한후 다음원소를 가리키는 반복자를 return
    //파라미터 value : 제거한후 성공하면 1 실패하면 0(값이 없으면!)
    if (s.find(15)!=s.end()) cout << "15 in s \n"; 
    //find 함수는 set 안에 value가 존재하면 반복자 return

    cout << s.size() << "\n";
    cout << s.count(150) << "\n"; 
    //value k의 갯수 반환 -> set은 0아니면 1!

    for (auto e : s) cout << e << ' ';
    cout << "\n";
    s.insert(-4);
    for (auto e : s) cout << e << ' ';

    auto it1 = s.begin();
    it1++;
    cout <<  *it1;
    auto it2 = prev(it1); //파라미터 반복자의 앞으로 이동
    cout << *it2;
    cout << *next(it2) << "\n";
    // advance(it2, -2); //iterator를 s.begin()앞으로 이동하면 segmentation fault 오류발생!
    auto it3 = s.lower_bound(-20); //전달인자 value k의 iterator
    auto it4 = s.find(15); //존재하면 그 15의 iterator값 반환. 존재하지않으면
    //아마 s.end()반환?
    cout << *it4 ;
}

int main(){
    set_example();
}