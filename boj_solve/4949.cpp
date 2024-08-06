#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main() {

    ios::sync_with_stdio(0); cin.tie(0);

    while (true) {
        string s;
        getline(cin, s);
        if (s == ".") break; // 왜 따옴표 두개인지
        bool isValid = true;
        stack<char> st;
        for (auto c : s) {
            if ((c == '(') || (c == '{') || (c == '[')) {
                st.push(c);
            }

            if ((c == ')') || (c == '}') || (c == ']')) {
                if (!st.empty()) {
                    char cur = st.top();
                    if (c == ')') {
                        if (cur == '(') {
                            st.pop();
                        } else {isValid = false; break;}
                    }
                    if (c == '}') {
                        if (cur == '{') {
                            st.pop();
                        }else {isValid = false; break;}
                    }
                    if (c == ']') {
                        if (cur == '[') {
                            st.pop();
                        }else {isValid = false; break;}
                    }
                } else { 
                    // cout << "no\n";
                    isValid = false; break;
                }
            }
        }

        if (!st.empty()) {
            isValid = false;
        }

        if (isValid) {
            cout << "yes\n";
        } else {
            cout << "no\n";
        }
    }
}