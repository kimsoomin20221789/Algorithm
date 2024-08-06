#include <bits/stdc++.h>
using namespace std;
int N;
int arr[20][20];
int minValue = INFINITY;
int vis[20] = {0};

int score() {
    int a = 0;
    int b = 0;
    for (int i=0; i<N; i++) {
        for (int j=0; j<N; j++) {
            if ((vis[i] == true) && (vis[j] == true)) {
                a += arr[i][j];
            } 
            if ((vis[i] == false) && (vis[j] == false)) {
                b += arr[i][j];
            } 
        }
    }
    return abs(b-a);
}

//person = 포함시키려는 학생의 배열 index
//cnt = 현재 몇번째 학생을 돌고 있는지
void backTracking(int person, int cnt) {
    vis[person] = 1;

    if (cnt == N/2) {
        minValue = min(minValue, score());
        return;
    }

    for (int i=person+1; i<N; i++) {
        backTracking(i, cnt+1);
        vis[i] = 0;
    }
}

int main() {
    //====== 설정 + 입력값 ===========
    ios::sync_with_stdio(false); cin.tie(NULL);

    cin >> N;
    for (int i=0; i<N; i++) {
        for (int j=0; j<N; j++) {
            cin >> arr[i][j];
        }
    }
    //==============================

    //백트래킹은 처음에는 시작은 젊반만 돈다! (어차피 뒤에는 겹칠 것이라고 예상)
    for (int i=0; i<N/2; i++) {
        memset(vis,0,sizeof(vis));
        backTracking(i, 1);
    }
    
    cout << minValue;
}