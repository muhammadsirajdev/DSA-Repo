#include <iostream>
#include <stack>
#include<string>
using namespace std;

string postfixsol(string str){
    stack<int>st;
    for (int i = 0; i < str.length(); i++)
    {
        char ch= str[i];
        int asci=(int)ch;
        if (asci>=48 && asci <=57)
        {
            st.push(asci-48);
        }else{
            int v2=st.top();st.pop();
            int v1=st.top();st.pop();
            if (ch=='+')
            {
                int v= v1+v2;
                st.push(v);
            }
            if (ch=='-')
            {
                int v= v1-v2;
                st.push(v);
            }
            if (ch=='*')
            {
                int v= v1*v2;
                st.push(v);
            }
            if (ch=='/')
            {
                int v= v1/v2;
                st.push(v);
            }
        }
        
    }
    stack<string>s;
    while (st.size()!=0)
    {
        int top = st.top();
        st.pop();
        string x = to_string(top);
        s.push(x);
    }
    return s.top();
}

int main(){
string str="23-4+567*+*";
string x =postfixsol(str);
cout<<x;
    return 0;
}