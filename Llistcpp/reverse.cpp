#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

struct Node* head = NULL;

void insert(int x) {
    Node* temp = new Node();
    temp->data = x;
    temp->next = NULL;
    if (head == NULL) {
        head = temp;
    } else {
        Node* current = head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = temp;
    }
}

void printReverse(struct Node* head) {
    if (head == NULL)
        return;

    printReverse(head->next);
    cout << head->data << " "; 
}

int main() {
    insert(2);
    insert(3);
    insert(4);
    insert(5);

    cout << "List printed in reverse order: ";
    printReverse(head); 

    return 0;
}
