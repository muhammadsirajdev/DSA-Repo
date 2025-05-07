#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node* prev;
    Node(int val) : data(val), next(nullptr), prev(nullptr) {}
};

class Deque {
private:
    Node* front;
    Node* rear;

public:
    Deque() : front(nullptr), rear(nullptr) {
        cout << "Deque initialized!" << endl;
    }

    bool isEmpty() {
        return front == nullptr;
    }

    void pushStart(int x) {
        Node* newNode = new Node(x);
        if (isEmpty()) {
            front = rear = newNode;
        } else {
            newNode->next = front;
            front->prev = newNode;
            front = newNode;
        }
        cout << "Inserted " << x << " at the front." << endl;
    }

    void pushBack(int x) {
        Node* newNode = new Node(x);
        if (isEmpty()) {
            front = rear = newNode;
        } else {
            newNode->prev = rear;
            rear->next = newNode;
            rear = newNode;
        }
        cout << "Inserted " << x << " at the rear." << endl;
    }

    void removeStart() {
        if (isEmpty()) {
            cout << "Deque is empty, cannot remove from front." << endl;
            return;
        }
        Node* temp = front;
        if (front == rear) { // Only one element
            front = rear = nullptr;
        } else {
            front = front->next;
            front->prev = nullptr;
        }
        cout << "Removed " << temp->data << " from the front." << endl;
        delete temp;
    }

    void removeEnd() {
        if (isEmpty()) {
            cout << "Deque is empty, cannot remove from rear." << endl;
            return;
        }
        Node* temp = rear;
        if (front == rear) { // Only one element
            front = rear = nullptr;
        } else {
            rear = rear->prev;
            rear->next = nullptr;
        }
        cout << "Removed " << temp->data << " from the rear." << endl;
        delete temp;
    }

    void display() {
        if (isEmpty()) {
            cout << "Deque is empty." << endl;
            return;
        }
        Node* current = front;
        cout << "Deque elements: ";
        while (current != nullptr) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }

    ~Deque() {
        while (!isEmpty()) {
            removeStart();
        }
    }
};

int main() {
    Deque dq;

    // Testing various operations
    dq.pushStart(5);
    dq.pushStart(6);
    dq.pushBack(7);
    dq.pushStart(8);
    dq.pushBack(9);
    dq.display(); // Expected output: 8 6 5 7 9

    // Removing elements from both ends
    dq.removeStart();
    dq.removeEnd();
    dq.display(); // Expected output: 6 5 7

    // Additional operations
    dq.pushBack(10);
    dq.pushStart(11);
    dq.display(); // Expected output: 11 6 5 7 10

    dq.removeStart();
    dq.removeEnd();
    dq.display(); // Expected output: 6 5 7

    return 0;
}
