# include <iostream>
using namespace std;

struct Node{
    int data;
    Node * next;
};
struct Node * head =NULL;
void push(int x){
    Node *temp=new Node();
    temp->data=x;
    temp->next=NULL;
    if (head ==NULL)
    {
        head=temp;
    }
    else{
        Node * t= head;
        while (t->next!=NULL)
        {
            t=t->next;
        }
        t->next=temp;
    }
}
void pop(){
    if (head ==NULL)
    {
        cout<<"The queue is empty"<<endl;
        return;
    }
    else{
        cout<<head->data<<endl;
        head=head->next;
    }
}
void peek(){
     if (head ==NULL)
    {
        cout<<"The queue is empty"<<endl;
        return;
    }
    else{
        cout<<head->data<<endl;
    }
}
void display(){
    if (head==NULL)
    {
        cout<<"The queue is empty"<<endl;
        return;
    }
    else{
        while (head!=NULL)
        {
            cout<<head->data<<endl;
            head=head->next;
        }
        
    }
    
}
int main(){
    push(1);
    push(2);
    push(3);
    push(4);
    push(5);
    push(6);
    // peek();
    pop();
    cout<<"After poping"<<endl;
    // peek();
    display();
    push(3);
    push(4);
    cout<<"peek"<<endl;
    peek();


    return 0;
}
