#include <iostream>
#include <stack>
#include <string>

using namespace std;

string infixToPostfix(string st1) {
    stack<string> val;  // Stack to hold values (operands)
    stack<char> st;     // Stack to hold operators
    string str = st1;

    for (int i = 0; i < str.length(); i++) {
        char ch = (char)str[i];

        // Handle numbers (operands)
        if (isalnum(ch))
 {  
            string s = " " + ch;
            val.push(s);
        } 
        else {
            if (st.empty() || ch == '(') {
                st.push(ch);
            } 
            else if (ch == ')') {
                // Process until '(' is found
                while (!st.empty() && st.top() != '(') {
                    string v2 = val.top(); val.pop();
                    string v1 = val.top(); val.pop();
                    char op = st.top(); st.pop();

                    // Correct order for postfix
                    string v = v1 + v2 + op;
                    val.push(v);
                }
                st.pop();  // Pop the '('
            } 
            else {
                // Operator precedence: * and / have higher precedence
                if (ch == '*' || ch == '/') {
                    while (!st.empty() && (st.top() == '*' || st.top() == '/')) {
                        string v2 = val.top(); val.pop();
                        string v1 = val.top(); val.pop();
                        char op = st.top(); st.pop();

                        // Correct order for postfix
                        string v = v1 + v2 + op;
                        val.push(v);
                    }
                    st.push(ch);
                } 
                // For + and -, process all operators with same or higher precedence
                else if (ch == '-' || ch == '+') {
                    while (!st.empty() && (st.top() == '*' || st.top() == '/' || st.top() == '+' || st.top() == '-')) {
                        string v2 = val.top(); val.pop();
                        string v1 = val.top(); val.pop();
                        char op = st.top(); st.pop();

                        // Correct order for postfix
                        string v = v1 + v2 + op;
                        val.push(v);
                    }
                    st.push(ch);
                }
            }
        }
    }

    // Process the remaining operators in the stack
    while (!st.empty()) {
        char op = st.top(); st.pop();
        string v2 = val.top(); val.pop();
        string v1 = val.top(); val.pop();

        // Correct order for postfix
        string v = v1 + v2 + op;
        val.push(v);
    }

    return val.top();  // The final postfix expression
}

int main() {
    string strr = "(a+b)-(k-x)/2*y+d";
    string postfix = infixToPostfix(strr);
    cout << "Postfix: " << postfix << endl;
    return 0;
}
