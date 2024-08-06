#include <iostream>

using namespace std;

int Answer;

int main(int argc, char** argv)
{
	int T, test_case;

    int a; int b; int c;
    int smallNum;
    int bigNum;
    int firstCount;
    int 나머지;
	cin >> T;
	for(test_case = 0; test_case  < T; test_case++)
	{
        
		Answer = 0;

        cin >> a >> b >> c;
        
        if (b<c){
            smallNum = b;
            bigNum = c;
        } else {
            smallNum = c;
            bigNum = b;
        }

        firstCount = a / smallNum;

        for (int i=firstCount; i>=0; i--){
            나머지 = a - i * smallNum;
            if ((나머지 % bigNum) == 0){
                Answer = (나머지 / bigNum + i);
                break;
            }
        }



		cout << "Case #" << test_case+1 << endl;
		cout << Answer << endl;
	}

	return 0;
}