#include <bits/stdc++.h>
using namespace std;

int n,m;
int arr[10];
bool isused[10];

void func(int k){
    //언제까지 가지를 쳐서 내려갈지!! 가지의 리프 노드들의 조건!!
    if(k==m){
        for (int i=0; i<m; i++){
            cout << arr[i] << " ";
        }
        cout << "\n";
        return;
    }

    for (int i=1; i<=n; i++){ //i는 자리에 들어갈 후보군, 가지를 칠때 노드에 들어갈 숫자들
        if(!isused[i]){ // if문은 i자리에 들어갈 조건 , 가지를 더 내려가기 위한 조건!
            arr[k] = i; //가지의 노드에 값넣기!
            isused[i] = 1;  //노드를 넣고 나서 해줘야되는 과정!
            func(k+1);
            isused[i] = 0; //나누어진 부분으로 다시 되돌아 올때 해야되는것!
        }
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    func(0);
}