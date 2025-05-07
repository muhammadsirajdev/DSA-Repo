# include <iostream>
using namespace std;
 struct Node{
    int data;
    Node * next;
 };
 struct Node * head =NULL;
 struct Node * temp = head;
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

 void remove_duplicate(struct Node * head){
    Node* t1=new Node();
    t1=head;
    while (t1!=NULL && t1->next!=NULL)
    {
        if (t1->data==t1->next->data)
        {
            t1->next=t1->next->next;
        }
        else
        {
            t1=t1->next;
        }
    }
 };
 void display() {
    Node* temp = head;  
    while (temp != NULL) {
        cout << temp->data << " "; 
        temp = temp->next;
    }
    cout << endl;  
};

 
 int main(){
    insert(60);
    insert(43);
    insert(43);
    insert(21);
    insert(11);
    insert(11);
    insert(11);
    remove_duplicate(head);
    display();
   

   
 }

 