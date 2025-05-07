#include <iostream>
#include <stack>
#include <string>

using namespace std;

string infixsol(string st1) {
    stack<string> val;
    stack<char> st;
    string str = st1;

    for (int i = 0; i < str.length(); i++) {
        char ch = str[i];
        int asci = (int)ch;

        if (asci >= 48 && asci <= 57) {  // Handle numbers
            string s = " " + ch;
            val.push(s);
        } else {
            if (st.size() == 0 || ch == '(') {
                st.push(ch);
            } 
            else if (ch == ')') {
                while (!st.empty() && st.top() != '(') {
                    string v2 = val.top(); val.pop();
                    string v1 = val.top(); val.pop();
                    char op = st.top(); st.pop();

                    string v = op + v2 + v1;  // Correct order for prefix
                    val.push(v);
                }
                st.pop();  // Pop the '('
            } 
            else {
                if (ch == '*' || ch == '/') {
                    if (st.top() == '*' || st.top() == '/') {
                        string v2 = val.top(); val.pop();
                        string v1 = val.top(); val.pop();
                        char op = st.top(); st.pop();

                        string v = op + v2 + v1;
                        val.push(v);
                    }
                    st.push(ch);
                } 
                else if (ch == '-' || ch == '+') {
                    while (!st.empty() && (st.top() == '*' || st.top() == '/' || st.top() == '+' || st.top() == '-')) {
                        string v2 = val.top(); val.pop();
                        string v1 = val.top(); val.pop();
                        char op = st.top(); st.pop();

                        string v = op + v2 + v1;
                        val.push(v);
                    }
                    st.push(ch);
                }
            }
        }
    }

    while (!st.empty()) {
        char op = st.top(); st.pop();
        string v2 = val.top(); val.pop();
        string v1 = val.top(); val.pop();

        string v = op + v2 + v1;
        val.push(v);
    }

    return val.top();
}

int main() {
    string strr = "(9-5)+3*4/2";
    string inf = infixsol(strr);
    cout << inf << endl;
    return 0;
}
