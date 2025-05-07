#include <iostream>
using namespace std;
struct Node{
    int data;
    Node*next;
};
struct Node * head=NULL;


void push(int x){
    Node * temp = new Node();
    temp->data=x;
    if (head==NULL || x<head->data)
    {
        temp->next=head;
        head=temp;
    }else{
        Node * t= head;
        while (t->next!=NULL && t->next->data<x)
        {
            t=t->next;
        }
        temp->next=t->next;
        t->next=temp;
    }
}
void pop(){
    if (head==NULL)
    {
        cout<<"empty"<<endl;
        return;
    }else{
        cout<<"The Pop element is: "<<head->data<<endl;
        head=head->next;
    }
}
void peek(){
    if (head==NULL)
    {
        cout<<"empty"<<endl;
        return;
    }else{
        cout<<"The Peek element is: "<<head->data<<endl;
    }
}
void display(){
    if (head==NULL)
    {
        cout<<"empty"<<endl;
        return;
    }
    else{
        Node * t=head;
        cout<<"The element in the queue are : "<<endl;
        while (t!=NULL)
        {
            cout<<t->data<<" | ";
            t=t->next;
        }
        cout<<endl;
    }
}
int main(){
    push(6);
    push(9);
    push(2);
    push(4);
    push(7);
    push(8);
    push(5);
    display();
    peek();
    pop();
    cout<<"display after poping"<<endl;
    display();
}