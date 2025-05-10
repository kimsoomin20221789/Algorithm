#include <bits/stdc++.h>
#include <iostream>
using namespace std;
vector<int> arr;
vector<int> answer;  // 현재 조합을 저장할 벡터

void combination(int total, int cnt, int cur) {
    if (cnt == total) {
        for (auto i : answer) {
            cout << i; 
        }

        cout << "\n";
        return;
    }
    if (cur >= arr.size()) return;  
    // o일때
    answer.push_back(arr[cur]);
    combination(total, cnt+1, cur+1);
    answer.pop_back();
    //x일때
    combination(total, cnt, cur+1);
}
int main() {
    arr = {1, 2, 3, 4};  // 조합을 구하고자 하는 배열
    int r = 2;  // 조합의 크기
    combination(r,0, 0);
}