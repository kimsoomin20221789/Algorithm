// 우선순위 큐 = 우선순위가 먼저인것부터 pop하는것
// 이진검색트리와는 다른 자료구조 , 힙은 최소값, 최대값에만 쓸수 있는 자료구조
// 힙은 이진검색트리와 다르게 높이가 같은것부터 , 왼쪽부터 나열해나감.
// insert 
// 삽입을 할때마다 두어야하는곳에 두고 많이 올라가도 힙의 최대높이만큼 올라감, ologn이 듦
// fetch(최소값 확인-최소힙)
// 몇번째 값은 확인하지못함 , 이진검색과의 차이
// 삭제(erase)
// 가장 마지막 노드와 바꾸고 , 올려준 값을 밑으로 계속 확인해나감.

// 이진트리 만드는법 -> 배열로 1번 인덱스부터 시작 2x, 2x+1, x/2
// 이진검색트리에서 값에 인덱스 번호를 붙여서 배열로 표현하지 못하는 이유는? -> 답찾아보자
#include <bits/stdc++.h>
// #include <iostream>
// #include <algorithm>
// #include <cmath>
// #include <queue>
using namespace std;

int heap[100005];
int sz = 0; // heap에 들어있는 원소의 수

void push(int x){
    // heap[sz] = x;
    // sz++;
    heap[++sz] = x;
    int idx = sz;
    while (idx!=1){ //계속 위로 올라가는부분
        int par = idx / 2;
        if (heap[par] <= heap[idx]) break;
        swap(heap[par], heap[idx]);
        idx = par;
    }
}

int top(){
    return heap[1];
}

void pop(){
    // heap[-1], heap[0] = heap[0], heap[-1];
    // int i = 1;
    // while (true){
    //     if (heap[i]>heap[2*i]){
    //         heap[i], heap[2*i] = heap[2*i], heap[i];
    //     } else if (heap[i]>heap[2*i+1]){
    //         heap[i], heap[2*i+1] = heap[2*i+1], heap[i];
    //     } else {return;}
    // }
    //길이줄이기 어떻게?? -> sz--
    heap[1] = heap[sz--];
    int idx = 1;
    while (2*idx <= sz){ //왼쪽자식이 leaf에 도달할때까지만 힙을 만들어줌, 
    //조심해야되는점은 자식의 오른쪽 노드가 없을수있음!! 확인해줘야함
        int lc = 2*idx, rc = 2*idx+1;
        int min_child = lc;
        if (rc<=sz && heap[rc]<heap[lc])
            min_child = rc;
        if(heap[idx]<=heap[min_child]) break;
        swap(heap[idx], heap[min_child]);
        idx = min_child;
    }
}

void test(){
  push(10); push(2); push(5); push(9); // {10, 2, 5, 9}
  cout << top() << '\n'; // 2
  pop(); // {10, 5, 9}
  pop(); // {10, 9}
  cout << top() << '\n'; // 9
  push(5); push(15); // {10, 9, 5, 15}
  cout << top() << '\n'; // 5
  pop(); // {10, 9, 15}
  cout << top() << '\n'; // 9
}

void stl_test(){
    // priority_queue<int> pq; //최대힙
    priority_queue<int, vector<int>, greater<int> > pq; //여기서 vector는 뭘의미?
    
    pq.push(10); pq.push(2); pq.push(5); pq.push(9);
    cout << pq.top() << "\n";
    pq.pop();
    pq.pop();
    cout << pq.top() << "\n";
    pq.push(5); pq.push(15);
    cout << pq.top() << "\n";
    pq.pop();
    cout << pq.top() << "\n";
    pq.push(5);
    pq.push(15);
    cout << pq.top() << "\n";
}
//비교함수를 다르게 쓸 수 있음
// Set과 priority queue의 차이점 왜냐면 둘이 시간복잡도가 똑같고 set의 기능이 다얌함
// 차이점: 수행속도가 빠르고(왜??), 공간도 적게 차지함(불균형이 없음)

 //비교함수란? 
    //compare 함수라고 했을때
    // cmp(a,b) = true 가 되어야함
    // cmp(a,a) = false가 되어야함 (비교인자로 같은값이 들어가면 무조건 false반환!! 비교함수이기 때문)
    //class에 cmp를 안쓰면 에러뜸 이유는 priority queue는 컨테이너이기 때문

class cmp {
public:
    bool operator()(int a, int b){
        if (abs(a) == abs(b)){
            return a > b; //왜ㅐ왜왜왜지...?
        }
        return abs(a) > abs(b);
    }
};

void boj_11286(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int N; cin >> N;
    priority_queue<int, vector<int>, cmp> pq;
    for (int i=0; i<N; i++){
        int x; 
        cin >> x;
        if (x != 0){
            pq.push(x);
        } else {
            //배열에서 절대값 가장 작은값을 출력하고 제거함. 절대값최소힙을 구현하고 pop하면 될듯?
            if (pq.empty()){
                cout << "0" << "\n";
            }else {
            cout << pq.top() << "\n";
            pq.pop();
            }
        }
    }
}


int main(){
  cout << "34" << endl;
//   boj_11286();
}
