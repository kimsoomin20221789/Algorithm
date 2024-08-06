//y=x 에 가까운 순서대로 좌표 정렬하기
#include <stdio.h>
#include <string.h>
#include <vector>
#include <iostream>
using namespace std;


struct Point {
    int x, y;
    Point(int xx, int yy): x(xx),y(yy){} //xx, yy는 입력값

};

bool comp(int a, int b){
    return a<b; //그대로면 return true(1) 
    //모든 원소에 대해 a<b라는 조건이 만족해야 이 정렬은 오름차순 정리가 된거라고 생각하자
}

bool comp(Point a, Point b){
    if (a.x == b.x) return a.y < b.y;
    return a.x < b.x; //x를 먼저 비교하고 y를 비교함, 반대로 하려면 x랑 y만 바꿔주자

}
vector<Point> v;
int main(){
    int N; cin >> N;
    for (int i=0; i<N; ++i){
        int a,b; cin>>a>>b;
        v.push_back(Point(a,b));
    }
    sort(v.begin(), v.end(), comp); //compare함수는 파이썬에서는 sort(key = lambda)랑
    //v.sort(key = lambda x:(x[0], -x[1]))
    for (auto it:v){
        cout << "(" << it.x << ", " << it.y << ")\n"
    }
}
