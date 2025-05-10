#include <string>
#include <vector>
#include <queue>
#include <unordered_set>
#include <algorithm>
#include <iostream>
using namespace std;
bool visited[20003];
vector<int> v[20003];

int solution(int n, vector<vector<int>> edge) {
    int answer = 0;
    
    queue<pair<int, int>> q;
    
    
    deque<int> dq;
    
    for (auto i : edge) {
        int st = i[0];
        int dest = i[1];

        v[st].push_back(dest);
    }
    
    q.push({1, 0});
    
    visited[1] = true;
    dq.push_back(0);
    
    while (!q.empty()) {
        auto cur = q.front();
        q.pop();
        
        for (auto i : v[cur.first]) {
            if (!visited[i]) {
                visited[i] = true;
                q.push({i, cur.second+1});
                cout << i;
                dq.push_back(cur.second+1);
            }
        }
    }
    
    sort(dq.begin(), dq.end());
    
    
    int maxVal = dq.back();
    for (int i=0; i<dq.size(); i++) {
        if (dq.back() == maxVal) {
            answer++;        
            dq.pop_back();
        } else {
            break;
        }
    }
    return answer;
}

int main() {
    cout << solution(6, {{3, 6}, {4, 3}, {3, 2}, {1, 3}, {1, 2}, {2, 4}, {5, 2}});
}