/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 17258                             :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: lucy1382 <boj.kr/u/lucy1382>                +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/17258                          #+#        #+#      #+#    */
/*   Solved: 2025/05/08 13:41:17 by lucy1382      ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */
#include <bits/stdc++.h>
using namespace std;
int arr[303]; // 욱제, 영선 친구 제외 count

bool cmp(pair<int, int> a, pair<int, int> b) {
    return a.second-a.first > b.second-b.first;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);


    int N; int M; int K; int T;
    cin >> N >> M >> K >> T;

    vector<pair<int, int>> v;

    for (int i=0; i<M; i++) {
        int a; int b; cin >> a >> b;
        for (int j=a; j<b; j++) {
            arr[j]++;
        }
    }

    int x = -1;
    int flag = 0;

    int st; int end;
    
    for (int i=1; i<=N; i++) {
        if (arr[i] != x) {
            if (flag == 0) {
                flag = 1;
                st = i;
                x = arr[i];
            } else {
                end = i-1;
                if (arr[i-1] < T) {
                    v.push_back({st, end});
                }
                flag = 0;
                i--;
            }
        }
    }
    v.push_back({st, N});


    sort(v.begin(), v.end(), cmp);

    for (auto i : v) {
        st = i.first;
        end = i.second;
        int needPerson = T-arr[st];

        if (K < needPerson){
            break;
        }

        for (int p=0; p<needPerson; p++) {
            for (int i=st; i<=end; i++) {
                arr[i]++;
            }
        }

        K-=needPerson;
    }

    int answer = 0;
    for (int i=1; i<=N; i++) {
        if (arr[i] >= T) {
            answer++;
        }
    }

    cout << answer;
}