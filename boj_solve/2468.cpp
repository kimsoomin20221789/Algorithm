#include <iostream>
#include <stack>
#include <queue>
#include <utility>
using namespace std;
#define PAIR pair<int, int>
int array0[100][100];
int array1[100][100];
// vector<int> v;
int N;
int cx[4] = {0, 0, -1, 1};
int cy[4] = {1, -1, 0, 0};
void bfs(int a, int b){
    array1[a][b] = 1; 
    queue<PAIR> q;
    
    q.push(PAIR(a, b));
    while (!q.empty()){
        PAIR d = q.front();
        q.pop();
        for (int i=0; i<4; i++){
            int dx = d.first + cx[i];
            int dy = d.second + cy[i];

            if (0<=dx && dx<N && 0<=dy&& dy<N && array1[dx][dy]==0) {
                q.push(PAIR(dx, dy));
                array1[dx][dy] = 1;
            }

        }

    }

}

int main(void){
    cin>>N;
    int max = 0;
    for (int i=0; i<N; i++){
        for (int j=0; j<N; j++){
            int a; cin >> a;
            if (a >= max){
                max = a;
            }
            array0[i][j] = a;
        }
        
    }

    int cnt = 0;
    // s.push(cnt);
    for (int h=0; h<=max; h++){
        for (int i=0; i<N; i++){
            for (int j=0; j<N; j++){
                if (array0[i][j] <= h){
                    array1[i][j] = 1;
                }
                else {array1[i][j] = 0;}
            }
        }

        int newCnt = 0;
        for (int i=0; i<N; i++){
            for (int j=0; j<N; j++){
                if (array1[i][j] == 0){
                
                    bfs(i, j);
                    newCnt++;
                }
            }
        }

        if (newCnt>cnt){
            cnt = newCnt;
            // s.push(cnt);
        }
    }

    cout << cnt;

}