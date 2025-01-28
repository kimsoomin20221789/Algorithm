#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int N; int M; cin >> N >> M;
    vector<string> pocketmons;
    map<string, int> pocketmontBook;
    for (int i=1; i<=N; i++) {
        string pocketmon; cin >> pocketmon;
        pocketmons.push_back(pocketmon);
        pocketmontBook[pocketmon] = i;
    }

    for (int i=0; i<M; i++) {
        string question; cin >> question;
        if (question[0] <= '9') {
            cout << pocketmons[stoi(question)-1] << "\n";
        } else {
            cout << pocketmontBook[question] << "\n";
        }
    }
}