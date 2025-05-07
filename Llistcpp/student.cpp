#include <iostream>
using namespace std;

struct Node {
    string name;
    int age;
    float gpa;
    string address;
    Node* next;
};
struct Node* head = NULL;

void addIncreasingly(string nam, int ages,float score, string addres) {
    Node* temp = new Node(); 
    temp->name = nam;
    temp->age=ages;
    temp->gpa=score;
    temp->address= addres;
    temp->next = NULL;
    
    if (head == NULL || score < head->gpa) {
        temp->next = head;
        head = temp;
    } else {
        Node* current = head;       
        while (current->next != NULL && current->next->gpa < score) {
            current = current->next;
        }
        temp->next = current->next;
        current->next = temp;
    }
}
void display() {
    Node* temp = head; 
    while (temp != NULL) {
        cout << temp->name << " ";
        
        cout << temp->age << " ";
        
        cout << temp->gpa << " ";
        
        cout << temp->address << " ";
        
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    addIncreasingly("ali",17,3.7,"ali pur");
    addIncreasingly("khan",19,3.2,"islamabad");
    addIncreasingly("syed",28,2.8,"skardu");
    // addIncreasingly(5);
    // addIncreasingly(4);
    // addIncreasingly(3);
    display();

    return 0;
}
