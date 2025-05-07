#include <iostream>
using namespace std;

struct Node {
    int data;
    Node * next;
};
struct Node * head = NULL;
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

Node* duplicate(struct Node * head){
    Node * dummy = new Node();
    dummy->next=head;
    Node * prev= new Node();
    prev= dummy;
    
        while (head!=NULL)
        {
             if (head->next!=NULL && head->data == head->next->data )
            {
             while (head->next!=NULL &&head->data==head->next->data )
             {
                head=head->next;
             }
           
             prev->next=head->next;
             
           
        }else
        {
            prev=prev->next;
           
        }
         head=head->next;
        }  
    
    return dummy->next;
};
void display(){
    Node * temp = head;
    while (temp!=NULL)
    {
        cout<<temp->data;
        temp=temp->next;
         cout<<endl;
    }
    cout<<endl;
};
int main(){
     insert(60);
    insert(43);
    insert(43);
    insert(21);
    insert(11);
    insert(11);
    insert(13);
    insert(11);
    head = duplicate(head);
    display();
}