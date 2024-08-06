#include <iostream>
using namespace std;
int countA;
int countB;
void changeA(){
    countA -= 1;
    countB += 1;
}

void changeB(){
    countA += 1;
}

int main(){
    countA = 1;
    countB = 0;
    int a;
    cin >> a;
    for (int i=0; i<a; i++){
        int aaa = countA;
        int bbb = countB;
        for (int j=0; j<aaa; j++){
            changeA();
        }

        for (int k=0; k<bbb; k++){
            changeB();
        }
    }
    cout << countA << " " << countB;
}