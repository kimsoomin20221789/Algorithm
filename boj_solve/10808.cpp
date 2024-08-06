#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false); 
    cin.tie(NULL);
    string s; cin >> s;
    for (char i = 'a'; i <= 'z'; i++){
        int cnt = 0;
        for (int j=0; j<s.size(); j++){ //auto c : s
            if (s[j] == i) cnt ++; 
        }
        cout << cnt << ' ';
    }
}

int freq[26]; // 전역변수(함수 밖)이면 알아서 0으로 초기화, 만약 지역변수로 만들었을시 fill()
int main() {
    ios::sync_with_stdio(false); 
    cin.tie(NULL);
    string s; cin >> s;
    for (auto c : s) {
        freq[c-'a']++;
    }
    for (int i=0; i<26; i++){
        cout << freq[i] << " ";
    }
}