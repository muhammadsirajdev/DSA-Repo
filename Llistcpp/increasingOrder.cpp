#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node * prev;

};
struct Node* head = NULL;

void addIncreasingly(int x){
    Node * c= new Node();
    c= head;
    Node* temp = new Node();
    temp->data= x;
    temp->next=NULL;
    temp->prev=NULL;
    if (head == NULL){
        head= temp;
    }else{
        if (temp->data<head->data)
        {
            temp->next=head;
            head=temp;
        }else if(temp->data>c->next->data)
        c=c->next;
    }temp->next = c->next;
    c->next=temp;
}

void display(){
    Node * temp = new Node();
    temp = head;
    while(temp!=NULL){
        cout<<temp->data;
        temp=temp->next;
    }cout << endl;
}
int main(){
    addIncreasingly(0);
    addIncreasingly(1);
    addIncreasingly(2);
    addIncreasingly(5);
    addIncreasingly(4);
    addIncreasingly(3);
    display();

    return 0;
}