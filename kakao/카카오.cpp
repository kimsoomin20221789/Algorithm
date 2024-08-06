#include <iostream>
#include <string>
using namespace std;

int main() {
    // 숫자를 저장할 변수
    string number;
    std::cout << "숫자를 입력하세요: ";
    std::cin >> number;

    // 숫자를 문자열로 변환
    // std::string numberStr = std::to_string(number);

    // 문자열 내에서 '4' 찾기
    if (number.find('4') != string::npos) {
        std::cout << "입력하신 숫자에 4가 포함되어 있습니다." << std::endl;
    } else {
        std::cout << "입력하신 숫자에 4가 포함되어 있지 않습니다." << std::endl;
    }

    return 0;
}
