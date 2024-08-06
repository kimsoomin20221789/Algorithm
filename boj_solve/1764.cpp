#include <iostream>
#include <string>
#include <map>
#include <vector>
using namespace std;

int main(){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n; int m;
    cin >> n >> m;
    map<string, int> map1;
    string s;
    for (int i=0; i<n+m; i++){
        cin >> s;
        map1[s]++;
    }
    int count = 0;
    vector<string> v;
    for (map<string, int>::iterator it = map1.begin(); it!=map1.end(); ++it){
        if (it->second > 1){
            count ++;
            v.push_back(it->first);
        }
    }

    cout << count << "\n";
    for (int i=0; i<v.size(); i++){
        cout << v[i] << "\n";
    }

}