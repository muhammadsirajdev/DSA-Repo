# include <iostream>
using namespace std;

struct Node {
    int data;
    Node * next;
};
struct Node* head = NULL;
void insert_start(int x) {
    Node* temp = new Node();
    temp->data = x;
    temp->next = NULL;  
    if (head == NULL) {
        head = temp;
    } else {
        temp->next = head;
        head = temp;
    }
};
void mid(struct Node* head){
    Node *fast=new Node();
    Node *slow = new Node();
    fast=head;
    slow=head;
    while (fast!=NULL && fast->next!=NULL)
    {
        slow=slow->next;
        fast=fast->next->next;
    }
    cout<<slow->data;
};
int main(){
    insert_start(1);
    insert_start(2);
    insert_start(3);
    insert_start(4);
    // insert_start(5);
    mid(head);
}
