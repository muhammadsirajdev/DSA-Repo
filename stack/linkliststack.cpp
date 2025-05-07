#include <iostream>
using namespace std;
class Node{
    public:
    int data;
    Node * next;
    Node(){}
    Node(int val){
        data=val;
        next=NULL;
    }
};
class linklist{
    public:
    Node * head;
    linklist(){head =NULL;}
    bool isempty(){
        return head==NULL;
    }
    void push(int x){
        Node * temp= new Node();
        temp->data=x;
        temp->next=NULL;
        if (isempty())
        {
            head=temp;
        }else{
            temp->next=head;
            head=temp;
        }
    }
    void peek(){
        cout<<" The peeked element is "<<head->data<<endl;
    }
    void pop(){
        cout<<" The pop element is "<<head->data<<endl;
        head=head->next;
    }
    void display(){
        Node *t = head;
        while (t!=NULL)
        {
            cout<<t->data<<" | ";
            t=t->next;
        }cout<<endl;
    }
};
int main(){
    linklist stack;
    stack.push(5);
    stack.push(4);
    stack.push(3);
    stack.push(2);
    stack.push(1);
    stack.push(0);
    stack.display();
    stack.peek();
    stack.pop();
    stack.peek();
    return 0;
}