
#include <iostream>
using namespace std;

const int MAX_SIZE = 100;
int f = -1, s = 0;  // f front hga ,and s to track size

void push(int arr[], int x, int size) {
    if (s >= size) {
        cout << "Queue overflow, cannot insert " << x << endl;
        return;
    }

    if (f == -1) {
        f = 0;
        arr[f] = x;
        s++;
    } else if (x < arr[0]) {
        // Shift all elements to the right to make room for the new smallest element
        for (int i = s; i > 0; i--) {
            arr[i] = arr[i - 1];
        }
        arr[0] = x;
        s++;
    } else {
        // Find the correct position for x to keep array in increasing order
        int j=s;
        int i;
        for (i = s - 1; i >= 0 && arr[i] > x; i--) {
            arr[i + 1] = arr[i];
        }
        arr[i + 1] = x;
        s++;
    }
}
void display(int arr[]){
    for (int i = 0; i < s; i++)
    {
        cout<<arr[i]<<" | ";
    }
    
}
int main(){
int size=5;
int arr[5];
push(arr,5,5);
push(arr,7,5);
push(arr,1,5);
push(arr,8,5);
push(arr,2,5);
display(arr);
return 0;
}
