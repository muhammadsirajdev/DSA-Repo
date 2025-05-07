#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
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
}
int check(int x){
    Node*temp=head;
    int indx=0;
     if (head == NULL) {
        return -1;
    }else{
        while (temp->data!=x)
        {
            temp=temp->next;
            indx++;

        }
        return indx;
        
    }
    
}

void display() {
    Node* temp = head;  
    while (temp != NULL) {
        cout << temp->data << " "; 
        temp = temp->next;
    }
    cout << endl;  
}

int main() {
    insert_start(5);
    insert_start(10);  
    insert_start(15);
    display();
    int see= check(10);
    cout<<see;
    return 0;
}
