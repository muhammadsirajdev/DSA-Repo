#include <iostream>
using namespace std;

int top=-1;

void push(int arr[],int x,int max,int &size){
if (top < max - 1) {
        top++;
        arr[top] = x;
        size++;
    } else {
        cout << "Stack overflow: " << endl;
    }
};
void pop(int arr[],int &size){
    if (top==-1)
    {
        cout<<"stack is empty "<<endl;
        return;
    }else{
        cout<<"The poped element is: ";
        cout<<arr[top]<<endl;
        top--;
        size--;
    }
}
void peek(int arr[]){
    if (top==-1)
    {
        cout<<"Stack is empty:"<<endl;
        return;
    }
    else{
        cout<<"The element on top is: ";
        cout<<arr[top];
    }
}
void display(int arr[]){
    if (top==-1)
    {
        cout<<"Stack is empty:"<<endl;
        return;
    }
    else{
        while (top!=-1)
        {
        cout<<"The element is: ";
        cout<<arr[top]<<endl;
        top--;
        }
    }
};
int* dltindx(int arr[],int indx,int &size,int max){
    if (indx>=size|| indx<0)
    {
        cout<<"Index out of bound"<<endl;
        return nullptr;
    }
    int *arr2= new int[max];
   int temp=top;
   int x=0;
   while (temp!=-1)
   {
    if (temp==indx-1)
    {
        temp--;
    }
    arr2[x]=arr[temp];
    x++;
    temp--;
   }
   top = x - 1; 
    size = x;    

    temp = 0; 
    while (temp < size) {
        arr[temp] = arr2[temp]; // Copy the new array back to the original stack
        temp++;
    }
   delete []arr2;
   return arr;
}
int main(){
    
    int max=5;
    int size=0;
    
    int* array = new int[max];
    push(array,1,max,size);
    push(array,2,max,size);
    push(array,3,max,size);
    push(array,4,max,size);
    push(array,5,max,size);
    push(array,6,max,size);
    // pop(array);
    // peek(array);
    // cout<<endl;
    // display(array);
    dltindx(array,3,size,max);
    cout<<"after deleting "<<endl;
    display(array);

    return 0;
}