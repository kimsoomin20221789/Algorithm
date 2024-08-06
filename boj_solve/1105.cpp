#include <iostream>
#include <string>
using namespace std;
int count1;
string L; string R;
void findCount(const char *a, const char *b){
    count1 = 0;
    int count2 = 0;
    for (int i=0; i<L.length(); i++){
        if (a[i] == '8' && b[i] == '8') {
            if (count2 == 0){
                count1 += 1;
            }
            continue;
        }
      
        if (a[i] != b[i]){
            count2 += 1;
        }
       
    }
}

int main(){
    cin >> L >> R;
    const char *arrayL = L.c_str();
    const char *arrayR = R.c_str();
    
    if (R.length() == L.length()){
        
        findCount(arrayL, arrayR);

    } else {
        count1 = 0; 
    }
    cout << count1;
}