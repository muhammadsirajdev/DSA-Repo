#include <iostream>
#include<stack>
using namespace std;

void solpost(string x){
    stack<int> st;
    for (int i = 0; i <x.length(); i++)
    {
        char ch= x[i];
        int asci=(int)ch;
        if (asci>=48 && asci <=57)
        {
            st.push(asci-48);
        }else{
            int v2=st.top();st.pop();
            int v1=st.top();st.pop();
            if (ch=='+')
            {
                st.push(v1+v2);
            }
            if (ch=='-')
            {
                st.push(v1-v2);
            }
            if (ch=='/')
            {
                st.push(v1/v2);
            }
            if (ch=='*')
            {
                st.push(v1*v2);
            }
            
        }
        
    }
    cout<<st.top();
}
int main(){
    string str="23-4+567*+*";
    solpost(str);
    return 0;
}