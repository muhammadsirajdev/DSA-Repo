#include <iostream>
using namespace std;

int f = -1;  // Front pointer
int r = -1;  // Rear pointer
int s = 0;   // Current size

void insertFront(int arr[], int size, int x) {
    if (s == size) {
        cout << "Deque is full\n";
        return;
    }

    if (s == 0) {  // If empty
        f = r = 0;
        arr[f] = x;
    } else if (f == 0) {  // Wrap around to the end
        f = size - 1;
        arr[f] = x;
    } else {  // Regular front insertion
        arr[--f] = x;
    }
    s++;
}

void insertAtrear(int arr[], int size, int x) {
    if (s == size) {
        cout << "Deque is full\n";
        return;
    }

    if (s == 0) {  // If empty
        f = r = 0;
        arr[r] = x;
    } else if (r == size - 1) {  // Wrap around to the front
        r = 0;
        arr[r] = x;
    } else {  // Regular rear insertion
        arr[++r] = x;
    }
    s++;
}

void display(int arr[], int size) {
    if (s == 0) {
        cout << "Deque is empty\n";
        return;
    }

    cout << "Deque elements: ";
    int i = f;
    while (true) {
        cout << arr[i] << " | ";
        if (i == r) break;  // Stop when front meets rear
        i = (i + 1) % size;  // Move to the next index (circularly)
    }
    cout << endl;
}

int main() {
    int size = 6;
    int arr[size];

    // Test cases
    insertFront(arr, size, 1);
    insertFront(arr, size, 2);
    insertFront(arr, size, 3);
    insertFront(arr, size, 4);
    insertAtrear(arr, size, 5);
    insertAtrear(arr, size, 6);

    display(arr, size);  // Display the elements in the deque

    return 0;
}
