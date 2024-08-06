#include <bits/stdc++.h>
using namespace std;

int T[15];
int P[15];
int ans[15];

int main() {
    ios::sync_with_stdio(false); 
    cin.tie(NULL);
    int N; cin >> N;
    for (int i=0; i<N; i++){
        int a; int b; cin >> a >> b;
        T[i] = a;
        P[i] = b;
    }

    for (int i=0; i<N; i++) {
        if (i+T[i] > N) {continue;}

        if (ans[i] < P[i]){
            ans[i] = P[i];
        }

        for (int j = i+T[i]; j<N; j++) {
            if (j+T[j] > N) {continue;}
            if (ans[j] < ans[i] + P[j]) {
                ans[j] = ans[i] + P[j];
            }
        }
    }

    int max = 0;
    for (int i=0; i<N; i++){
        if(ans[i] > max){
            max = ans[i];
        }
    }
    cout << max;
}
