#include <iostream>
using namespace std;
class stack{
    public:
    int size;
    int *arr;
    int top=-1;
    
    stack(int s){
        size=s;
        arr= new int[size];
    }

    bool isempty(){
        return top==-1;
    }
    bool isfull(){
        return top==size-1;
    }
    void push(int x){
        if (isfull())
        {
            cout<<"stack is full"<<endl;
            return;
        }
        else {
        arr[++top]=x;
        }
        
    }
    void peek(){
        cout<<"the top most element is " <<arr[top]<<endl;
    }
    void display(){
        for (int i = 0; i <= top; i++)
        {
            cout<<arr[i]<<" | ";
        }cout<<endl;   
    }
};
int main(){
    stack st(5);
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    st.push(5);
    st.display();
    st.peek();
    return 0;
    }