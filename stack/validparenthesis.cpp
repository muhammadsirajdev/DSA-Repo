#include <iostream>
#include <stack>
#include <string>

class Solution {
public:
    bool isValid(std::string s) {
        std::stack<char> st; // Create a stack to hold characters

        for (int i = 0; i < s.length(); i++) {
            char ch = s[i];

            // Push opening brackets onto the stack
            if (ch == '(' || ch == '[' || ch == '{') {
                st.push(ch);
            } 
            // Check for closing brackets
            else {
                if (st.empty()) {
                    return false; // Return false if stack is empty when encountering a closing bracket
                }

                if (ch == ')') {
                    if (st.top() == '(') {
                        st.pop(); // Pop if matches
                    } else {
                        return false; // Return false if it doesn't match
                    }
                } 
                else if (ch == ']') {
                    if (st.top() == '[') {
                        st.pop(); // Pop if matches
                    } else {
                        return false; // Return false if it doesn't match
                    }
                } 
                else if (ch == '}') {
                    if (st.top() == '{') {
                        st.pop(); // Pop if matches
                    } else {
                        return false; // Return false if it doesn't match
                    }
                }
            }
        }

        return st.empty(); // Return true if the stack is empty, otherwise false
    }
};

int main() {
    Solution solution;
    std::string test = "[()]{}{[()()]()}"; // Example input
    if (solution.isValid(test)) {
        std::cout << "Valid" << std::endl;
    } else {
        std::cout << "Invalid" << std::endl;
    }
    return 0;
}
