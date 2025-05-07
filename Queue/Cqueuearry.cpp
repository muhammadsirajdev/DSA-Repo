#include <iostream>
#include<queue>
using namespace std;
int f=0;
int r=-1;
int s=0;

void add(int arr[],int size,int x){
    if (s==size)
    {
        cout<<"Stack is full"<<endl;
        return;
    }
    else if (r<size-1)
    {
        r++;
        arr[r]=x;
        s++;
    }else{
        r=0;
        arr[r]=x;
        s++;
    }
}
void removes(int  arr[],int size){
    if (s==0)
    {
        cout<<"stack is empty"<<endl;
        return;
    }else if(f<r){
        f++;
        s--;
    }
    else if(f==size-1){
        f=0;
        s--;
    }
}
bool Isempty(int arr[]){
    if (s==0)
    {
        return true;
    }
    else{
        return false;
    }
}
void peek(int arr[]){
    if (s==0)
    {
        cout<<"empty stack"<<endl;
        return;
    }
    else{
        cout<<arr[f]<<endl;
    }
    
}
void pop(int arr[]){
     if (s==0)
    {
        cout<<"empty stack"<<endl;
        return;
    }
    else{
        f++;
        s--;
    }
}
void display(int  arr[], int size){
    if (s==0)
    {
        cout<<"empty stack"<<endl;
        return;
    }
   if (r >= f) {
        for (int i = f; i <= r; i++) {
            cout << arr[i] << " ";
        }
    } 
    
    else {
        for (int i = f; i < size; i++) {
            cout << arr[i] << " ";
        }
        for (int i = 0; i <= r; i++) {
            cout << arr[i] << " ";
        }
    }
    cout << endl;
}

int main(){
int size=5;
int arr[size];

add(arr,size,2);
add(arr,size,3);
add(arr,size,4);
add(arr,size,5);
display(arr,size);
removes(arr,size);
cout<<"after removing"<<endl;
display(arr,size);
cout<<" display after re-added elements"<<endl;
add(arr,size,6);
add(arr,size,7);
display(arr,size);
cout<<"peeked element is"<<endl;
peek(arr);
pop(arr);
cout<<"peeked element after poping is"<<endl;
peek(arr);
cout<<Isempty(arr);

return 0;
}
