#include <bits/stdc++.h>
using namespace std;
int arr[403][403];
int n; int k; 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> k;

    for (int i=0; i<k; i++) {
        int beforeAccident; int afterAccident;
        cin >> beforeAccident >> afterAccident;
        arr[beforeAccident][afterAccident] = -1;
        arr[beforeAccident][afterAccident] = 1;
    }

    for (int k=1; k<=n; k++) {
        for (int i=1; i<=n; i++) {
            for (int j=1; j<=n; j++) {
                if (arr[i][j] == 0) {
                    if (arr[i][k] == 1 && arr[k][j] == 1) {
                        arr[i][j] = 1;
                    } else if (arr[i][k] == -1 && arr[k][j] == -1) {
                        arr[i][j] = -1;
                    }
                }
            }
        }
    }
    
    int s;
    cin >> s;
    for (int i=0; i<s; i++) {
        int a; int b;
        cin >> a >> b;
        cout << arr[a][b] << "\n";
    }
}