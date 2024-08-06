//모듈러 연산
7*9 mod 4 = 3  //이렇게 하면 자릿수가 터져버릴수있음
-> (7%4 x 9%4)%4


//소인수 분해
for (int i=2; i*i<=K; ++i) 


// 루트를 사용하는 자료형을 따로 두지 않아도 되는 trick

//최대공약수, 최소공배수
//최소공배수 : 두개의 수의 곱 / 최대공약수
//최대공약수를 소인수분해 사용하지 않고 하는법 : 호제법
//gcd는 최대공약수, lcm은 최소 공배수
int gcd(int a, int b) {
	if(b == 0) return a;
	return gcd(b, a%b);
}
long long lcm (int a, int b) {
	return a/gcd(a, b) * b;
}

#include <iostream>
using namespace std;
int main(){
    
}

//에라토스테네스의 체
//소수를 구하는 알고리즘
//i = range(2~루트 N)
// 각각의 i에 대해 i*i~N의 i의 배수들을 지움
#include <iostream>
#include <vector>
using namespace std;
const int MAX_N = 1e6; // 백만
bool isErased[MAX_N+1];
// isErased[p] == false : p가 아직 안지워졌다.
// isErased[p] == true  : p가 지워졌다.
int main(){
    int N; cin >> N;

    isErased[0] = true;
    isErased[1] = true;
    for(int p=2; p*p <=N; ++p){
        if(isErased[p]) continue;
        for(int j=p*p; j<=N; j+=p){
            isErased[j]=true;
        }
    }
    while(true){
        int K; cin >> K;
        if(isErased[K]) cout << "소수 아님" << '\n';
        else cout << "소수!" << '\n';
    }
}