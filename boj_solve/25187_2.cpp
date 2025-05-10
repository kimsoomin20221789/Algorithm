#include <bits/stdc++.h>
using namespace std;

int arr[100003];

vector<int> par[100003];

void init(int N) {
    for(int i=0; i<N; ++i){
        if (arr[i]) {
            par[i] = {i, 0, 1};
        } else {
            par[i] = {i, 1, 0};
        }
    }
}

vector<int> find(int x) {
    if(x==par[x][0]) return par[x];
    par[x]=find(par[x][0]);
    return par[x];
}

void unite(int x, int y) {
    auto i = find(x);
    auto j = find(y);
    if (i==j) {return;}
    par[i[0]][0]=j[0];
    par[j[0]][1]=i[1] + j[1];
    par[j[0]][2]=i[2] + j[2];
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int N; int M; int Q; cin >> N >> M >> Q;

    for (int i=0; i<N; i++) {
        cin >> arr[i];
    }

    init(N);

    for (int i=0; i<M; i++) {
        int a; int b; cin >> a >> b;
        unite(a-1, b-1);
    }

    for (int i=0; i<Q; i++) {
        int x; cin >> x;
        if (find(x-1)[1] < find(x-1)[2]) {
            cout << "1" << "\n";
        } else {
            cout << "0" << "\n";
        }
    }
}