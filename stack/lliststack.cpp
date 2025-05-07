#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
};
struct Node * head =NULL;
Node *top = NULL;

void push(int x){
    Node *temp=new Node();
    temp->data=x;
    temp->next = head;
    head=temp;
}
void peek(){
    cout<<"The top most element is: "<<endl;
    cout<<head->data<<endl;
}
void pop(){
    cout<<"The popped most element is: "<<endl;
    cout<<head->data<<endl;
    head=head->next;
}
void display() {
    if (head == NULL) {
        cout << "Stack is empty" << endl;
        return;
    }

    Node* temp = head;
    while (temp != NULL) {
        cout << "The element is: " << temp->data << endl;
        temp = temp->next;
    }
}
int main(){
    push(1);
    push(2);
    push(3);
    push(4);
    push(5);
    peek();
    pop();
    peek();
    display();
    return 0;
}
