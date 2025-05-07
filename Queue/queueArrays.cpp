#include <iostream>
#include <queue>
using namespace std;
int s=0;
int r=-1;
int f=-1;
void push(int arr[],int size,int e){
    
    if (r==size-1)
    {
        cout<<"queue is full";
        return;
    }
    if (f==-1)
    {
        f++;
    }
    r++;
    arr[r]=e;
    s++;
}
void pop(int arr[]){
    if (s==0)
    {
        cout<<"queue is empty"<<endl;
        return;
    }
    else{
    cout<<arr[f]<<endl;
    f++;
    s--;
}
}
void peek(int arr[]){
    if (s==0)
    {
        cout<<"queue is empty"<<endl;
        return;
    }
    else{
        cout<<arr[f]<<endl;
    }
    
}



int main(){
    int size;
    size=5;
    int arr[size];
    push(arr,size,1);
    push(arr,size,2);
    push(arr,size,3);
    push(arr,size,4);
    push(arr,size,5);
    // peek(arr);
    // pop(arr);
    // peek(arr);
    push(arr,size,6);

}