#include <iostream>
using namespace std;
struct Node{
    int data;
    Node* next;
};
     struct Node* head = NULL;
     void insert(int x){
        Node*temp = new Node();
        temp->data=x;
        temp->next=NULL;
        if(head == NULL){
            head=temp;
        }else{
            temp->next=head;
            head=temp;
        }
     };
     void insert_end(int a){
        Node * tail = new Node();
        tail=head;
        Node * temp = new Node();
        temp->data=a;
        temp->next=NULL;
        if (head==NULL){
            head=temp;
        }else
        {
            while (tail->next!=NULL)
            {
                tail=tail->next;
            }
            tail->next=temp;
                temp=tail;
            
        }
        
     };
     void insert_anylocation(int x,int j){
        Node * temp = new Node();
        Node * t= new Node();
        t=head;
        temp->data=x;
        temp->next=NULL;
        if (head==NULL)
        {
            head=temp;
        }else{
           for (size_t i = 1; i < 2; i++)
           {
             t= t->next;
           }
            temp->next=t->next;
            t->next=temp;
        }
        
     };
     void print(){
        Node*temp = new Node();
        temp=head;
        while (temp!=NULL)
        {
             cout<<temp->data<<"\n";
             temp=temp->next;
        }
        
     };
     int main(){
        insert(2);
        insert_end(3);
        insert_anylocation(4,2);
        insert_end(5);
        insert(1);
        insert_end(6);
        print();
        return 0;
     }
