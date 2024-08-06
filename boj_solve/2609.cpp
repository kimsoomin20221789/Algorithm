#include <iostream>
using namespace std;
int gcd(int a, int b) {
	if(b == 0) return a;
	return gcd(b, a%b);
}
long long lcm (int a, int b) {
	return a/gcd(a, b) * b;
}
int main(){
    int a; int b;
    cin >> a >> b;
    cout << gcd(a, b) << "\n";
    cout << lcm(a, b);
}