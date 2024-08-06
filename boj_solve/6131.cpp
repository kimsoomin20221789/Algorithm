#include <iostream>
#include <cmath>
using namespace std;

bool isPowerOfTwo(int n) {
    if (n <= 0) {
        return false;  // 음수나 0은 거듭제곱이 아님
    }
    
    while (n > 1) {
        if (n % 2 != 0) {
            return false;  // 2로 나누어 떨어지지 않으면 거듭제곱이 아님
        }
        n /= 2;
    }
    
    return true;  // 마지막에 1이 되면 거듭제곱
}


int main(){
    int K = 500;
    int N;  cin >> N;
    int cnt = 0;
    int a;
    for (int i=1; i<=sqrt(K); i++){
        a = i*i + N;
        if (a > 500){
            break;
        }
        if (isPowerOfTwo(a)){
            cnt += 1;
        }
        else {
            continue;
        }
    }
    cout << cnt;
}