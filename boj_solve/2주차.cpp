
#include <string>
#include <vector>
#include <iostream>
using namespace std;
typedef first X;
int main() {
    pair<int, int> s;
}

// #include <string>
// #include <vector>
// #include <iostream>
// using namespace std;
// int answer;
// int total;
// int lastIndex;
// int targetVal;

// void dfs(vector<int>& numbers, int cnt) {
//     total += numbers[cnt];
//     if (cnt !=  lastIndex) {
//         cout << total << "\n";
//         dfs(numbers, cnt+1);
//     } else {
//         cout << total<< "\n";
//         if (total == targetVal) {
//             answer++;
//             cout << "!!" << answer;
//         }
//     }
    
//     total = total - numbers[cnt] * 2;
//     if (cnt !=  lastIndex) {
//         cout << total<< "\n";
//         dfs(numbers, cnt+1);
//     } else {
//         cout << total << "\n";
//         if (total == targetVal) {
//             answer++;
//             cout << "!!" << answer;
//         }
//     }
    
//     total += numbers[cnt];
// }
// int solution(vector<int> numbers, int target) {
//     targetVal = target;
//     lastIndex = numbers.size() - 1;
    
//     dfs(numbers, 0);
    
//     return answer;
// }
// int main() {
//     int x = solution({1,1,1}, 2);
//     cout << x;
// }