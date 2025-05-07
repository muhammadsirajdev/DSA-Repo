# include <iostream>
using namespace std;

struct Node{
    int data;
    Node * next;
};
struct Node* head = NULL;
struct Node* tail =NULL;

void insertAtstart(int x){
    Node * temp = new Node();
    temp->data=x;
    temp->next=NULL;
    if (head == NULL)
    {
        head=temp;
        tail=temp;
        temp->next=head;
    }
    else{
        temp->next=head;
        tail->next=temp;
        head=temp;
    }
};
void insertAtEnd(int x){
      Node * temp = new Node();
    temp->data=x;
    temp->next=NULL;
    if (head == NULL)
    {
         head=temp;
        tail=temp;
        temp->next=head;
    }else{
        tail->next=temp;
        tail=temp;
        tail->next=head;
    }
    
}
void insertAtMiddle(int x,int p){
    Node* temp = new Node();
    temp->data=x;
    temp->next=NULL;
    if (head == NULL)
    {
        head=temp;
        tail=temp;
        temp->next=head;
    }else{
        Node *curr = head;
        for (int i = 1; i < p; i++)
        {
            curr=curr->next;
        }
        temp->next=curr->next->next;
        curr->next=temp;
        
    }
    
}
void display(){
    Node * temp = new Node();
    temp=head;
    if (head!=NULL)
    {
        do
        {
            cout<<temp->data<<endl;
            temp=temp->next;
        } while (temp!=head);
        cout<<endl;
    }
    
}
int main(){
    insertAtstart(5);
    insertAtstart(4);
    insertAtstart(3);
    insertAtstart(2);
    insertAtstart(1);
    insertAtstart(0);
    insertAtEnd(6);
    insertAtstart(-1);
    insertAtMiddle(9,3);
    display();
}