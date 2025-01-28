#include <iostream>
#include <numeric>

int main() {
    int a = 12;
    int b = 18;

    int gcd_result = std::gcd(a, b);
    int lcm_result = std::lcm(a, b);

    std::cout << "GCD of " << a << " and " << b << " is " << gcd_result << std::endl;
    std::cout << "LCM of " << a << " and " << b << " is " << lcm_result << std::endl;

    return 0;
}