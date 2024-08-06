#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Point {
    int x, y;
    Point(int x1, int y1): x(x1), y(y1) {}
};

bool comp(Point a, Point b){
    return a.y < b.y;
}

int main(){
    vector<Point> v1;
    int N; cin >> N;
    int a[N];
    int b[N];

    for (int i=0; i<N; i++){
        int first; int second; cin >> first >> second;
        v1.push_back(Point(first, second));
    }

    sort(v1.begin(), v1.end(), comp);
    for (int i=0; i<v1.size(); i++){
        if (v1[i].y > v1[i+1].x){
            v1.erase(v1.begin()+i+1);
            
        }
    }

    cout << v1.size();
}