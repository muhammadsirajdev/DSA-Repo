#include <iostream>
#include <stack>
#include <string>

using namespace std;

string infixsol(string st1){
    stack<int> val;
    stack<char>st;
    string str=st1;
    for (int i = 0; i < str.length(); i++)
    {
        char ch= str[i];
        int asci= (int)ch;
        if (asci>=48 && asci <= 57)
        {
            val.push(asci-48);
        }
        else{
            if (st.size()==0 || ch=='(')
            {
                st.push(ch);
            }
        // If the character is a closing parenthesis, solve the expression inside the parentheses
        else if (ch == ')') {
            while (!st.empty() && st.top() != '(') {
                int v2 = val.top(); val.pop();
                int v1 = val.top(); val.pop();
                char op = st.top(); st.pop();
                 if (op=='+')
        {
            int v = v1 + v2;
            val.push(v);
        }
        if (op=='-')
        {
         int v = v1 - v2;
         val.push(v);  
               
        }
        if (op=='*')
        {
        int v = v1 * v2;
        val.push(v);
        }
        if (op=='/')
        {
        int v = v1 /v2;
        val.push(v);
        }
                
            }
            st.pop();  // Pop the '('
        }
            else{
                if (ch=='*'|| ch=='/')
                {
                    if (st.top()=='*')
                    {
                       int v2=val.top();
                       val.pop();
                       int v1=val.top();
                       val.pop();
                       int v = v1 * v2;
                       val.push(v);
                       st.pop();
                    }
                    
                    else if(st.top()=='/'){
                        int v2=val.top();
                       val.pop();
                       int v1=val.top();
                       val.pop();
                       int v = v1 / v2;
                       val.push(v);
                       st.pop();
                    }
                    st.push(ch);
                }
               else if (ch=='-'|| ch=='+')
                {
                     if (st.top()=='*')
                    {
                       int v2=val.top();
                       val.pop();
                       int v1=val.top();
                       val.pop();
                       int v = v1 * v2;
                       val.push(v);
                       st.pop();
                    }
                    if(st.top()=='/'){
                       int v2=val.top();
                       val.pop();
                       int v1=val.top();
                       val.pop();
                       int v = v1 / v2;
                       val.push(v);
                       st.pop();
                    }
                    if(st.top()=='+'){
                        int v2=val.top();
                       val.pop();
                       int v1=val.top();
                       val.pop();
                       int v = v1 + v2;
                       val.push(v);
                       st.pop();
                    }
                    if(st.top()=='-'){
                        int v2=val.top();
                       val.pop();
                       int v1=val.top();
                       val.pop();
                       int v = v1 - v2;
                       val.push(v);
                       st.pop();
                    }
                    st.push(ch);
                }
            }
            
        }
        
    }

    while (val.size()>1)
    {
        // int v2=val.top();
        // val.pop();
        // int v1=val.top();
        // val.pop();
        
        char c = st.top();
        st.pop();
        if (c=='+')
        {
            int v2=val.top();
            val.pop();
            int v1=val.top();
            val.pop();
            int v = v1 + v2;
            val.push(v);
        }
        if (c=='-')
        {
         int v2=val.top();
         val.pop();
         int v1=val.top();
         val.pop();
         int v = v1 - v2;
         val.push(v);  
               
        }
        if (c=='*')
        {
        int v2=val.top();
        val.pop();
        int v1=val.top();
        val.pop();
        int v = v1 * v2;
        val.push(v);
        }
        if (c=='/')
        {
        int v2=val.top();
        val.pop();
        int v1=val.top();
        val.pop();
        int v = v1 /v2;
        val.push(v);
        }
    }
    stack<string>s;
    while (val.size()!=0)
    {
        int top = val.top();
        val.pop();
        string x = to_string(top);
        s.push(x);
    }
    return s.top();
}
int main(){
    string strr= "(9-5)+3*4/2";
    string inf= infixsol(strr);
    cout<<inf<<endl;


    return 0;
}