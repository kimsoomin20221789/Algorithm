#include <iostream>
#include <map>
#include <string>
using namespace std;
int main(){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int N; int M;
    map<string, string> m;
    cin >> N >> M;
    string url;
    string password;
    for (int i=0; i<N; i++){
        cin >> url >> password;
        m[url] = password;
    }
    string value;
    for (int i=0; i<M; i++){
        cin >> value;
        cout << m[value] << "\n";
    }
}