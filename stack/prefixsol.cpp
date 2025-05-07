#include <iostream>
#include <stack>
#include <string>
using namespace std;

string postfixsol(string str) {
    stack<int> st;
    for (int i = str.length() - 1; i >= 0; i--) { // Corrected loop
        char ch = str[i]; // Access valid index
        int asci = (int)ch;
        if (asci >= 48 && asci <= 57) {
            st.push(asci - 48); // Push digit value
        } else {
            if (st.size() < 2) { // Check stack size
                cerr << "Error: Not enough operands." << endl;
                return ""; // Handle error
            }
            int v1 = st.top(); st.pop(); // Pop second operand
            int v2 = st.top(); st.pop(); // Pop first operand
            if (ch == '+') {
                st.push(v1 + v2);
            } else if (ch == '-') {
                st.push(v1 - v2);
            } else if (ch == '*') {
                st.push(v1 * v2);
            } else if (ch == '/') {
                if (v2 == 0) {
                    cerr << "Error: Division by zero." << endl;
                    return ""; // Handle error
                }
                st.push(v1 / v2);
            }
        }
    }
    
    // Converting final result to string
    stack<string> s;
    while (!st.empty()) {
        int top = st.top();
        st.pop();
        s.push(to_string(top));
    }
    return s.top(); // Return the string representation of the result
}

int main() {
    string str = "-9/*+5346"; // Note: Invalid postfix expression
    string x = postfixsol(str);
    cout << x;
    return 0;
}
