#include <iostream>
#include <stack>
#include <string>

using namespace std;

string infixToPrefix(const string& str) {
    stack<string> val; // Stack to store operands
    stack<char> op; // Stack to store operators

    for (size_t i = 0; i < str.length(); i++) {
        char ch = str[i];
        
        // Check if the character is a digit
        if (isdigit(ch)) {
            val.push(string(1, ch)); // Push the character as a string
        } 
        // If current character is '(', push to operator stack
        else if (op.empty() || ch == '(' || op.top() == '(') {
            op.push(ch);
        } 
        // If current character is ')', process the operators until '(' is found
        else if (ch == ')') {
            while (op.top() != '(') {
                string v2 = val.top(); val.pop();
                string v1 = val.top(); val.pop();
                char o = op.top(); op.pop();

                string put = o + v1 + v2;
                val.push(put);
            }
            op.pop(); // Pop the '('
        } 
        // Process operators
        else {
            if ((ch == '*' || ch == '/') && (op.top() == '+' || op.top() == '-')) {
                op.push(ch);
            } 
            else if (ch == '+' || ch == '-') {
                string v2 = val.top(); val.pop();
                string v1 = val.top(); val.pop();
                char o = op.top(); op.pop();
                string put = o + v1 + v2;
                val.push(put);
                op.push(ch);
            } 
            else if ((ch == '*' || ch == '/') && (op.top() == '*' || op.top() == '/')) {
                string v2 = val.top(); val.pop();
                string v1 = val.top(); val.pop();
                char o = op.top(); op.pop();
                string put = o + v1 + v2;
                val.push(put);
                op.push(ch);
            }
        }
    }

    // Process remaining operators
    while (!op.empty()) {
        string v2 = val.top(); val.pop();
        string v1 = val.top(); val.pop();
        char o = op.top(); op.pop();
        string put = o + v1 + v2;
        val.push(put);
    }

    return val.top(); // Return the final prefix expression
}

int main() {
    string str = "9-(5+3)*4/6";
    string prefix = infixToPrefix(str);
    cout << prefix << endl;
    return 0;
}
