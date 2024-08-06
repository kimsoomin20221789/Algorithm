// #include <iostream>
// #include <queue>
// #include <vector>
// #include <set>
// #include <map>
#include <bits/stdc++.h>
using namespace std;
struct comp {
        bool operator()(int a, int b){
            return a > b;
        }
};
//마지막엔 비교함수
int main(){
    priority_queue<int> pq1; // Max Heap
    priority_queue<int, vector<int>, greater<int> > pq2; // Min Heap
    priority_queue<int, vector<int>, comp> pq3; // Min Heap

    pq1.push(3);
    pq1.push(2);
    pq1.push(5);
    cout << pq1.top() << "\n"; // 5
    pq1.pop();

    //BinarySearch 트리는 모든 노드에 대하여 왼쪽자식 < 부모 < 오른쪽 자식
    //최악이 생길 수 있어, 항상 트리의 균형을 유지시켜주는 자료구조가 balanced BinarySearch 트리
    //이로 구현한 구현체가 Set
    //>> set은 search할때 빠르다!!

    //erase(x), find(x), insert(x)
    set<int> s;
    s.insert(1);
    if (s.find(2) != s.end()){
        cout << "2 found!";
    }
    s.erase(1);

    //set은 정렬된 상태로 되어있어 순회할경우 정렬되어 있는 상태임!!
    //대신 일반배열과 순회하는 방법이 다르다 ㅎ.ㅎ
    s.insert(1);
    s.insert(3);
    s.insert(2);
    for (set<int>::iterator it = s.begin(); it!=s.end(); ++it){
        cout << *it << " ";
    }

    
    map<string, int> m;
    m["asdf"] = 3;
    m["qwer"]++;

    // unordered_map을 활용하면 hash map을 사용할 수 있습니다.
    // 중복 키 허용인 multimap도 있습니다.

    for(map<string, int>::iterator it=m.begin(); it!=m.end(); ++it){
        cout << it->first << " : key, " << it->second << " : value" << endl;
    }
    //마찬가지로 auto로 간소화 가능
}