# include <iostream>
using namespace std;
int r,f=-1;
int s=0;
void insertAtEnd(int x,int size,int arr[]){
    if (s==size)
    {
        cout<<"stack overflown"<<endl;
        return;
    }
    if (f==-1)
    {
        f=r=0;
        arr[r]=x;
        s++;
    }
    r++;
    arr[r]=x;
}
void insertAtStart(int arr[],int x,int size){
    if (f==-1)
    {
        f=0;
        arr[++r]=x;
        s++;
    }
    
    else if (s==size)
    {
        cout<<"stack overflown"<<endl;
        return;
    }
    else if (f!=0)
    {
        arr[--f]=x;
        s++;
    }else{
        cout<<"stack underflow"<<endl;
    }
}
void removeAtstart(int arr[],int size){
   if(f==-1) {
      cout<<"deletion is not possible::dequeue is empty";
      return;
   }
   else {
      cout<<"the deleted element is:"<<arr[f];
      if(f==r) {
         f=r=-1;
         return;
      } else
         f=f+1;
      }
}
void removeAtend(int arr[],int size){
   if(f==-1) {
         cout<<"deletion is not possible::dequeue is empty";
         return;
      }
      else {
         cout<<"the deleted element is:"<<arr[r]<<endl;
         if(f==r) {
            f=r=-1;
         } else
            r=r-1;
      }
    
}
void display(int arr[]){
    if (s!=0)
    {
        for (int i = f; i <=r; i++)
        {
            cout<<arr[i]<<endl;
        }
    }
    else{
        cout<<"stack empty"<<endl;
        return;
    }
    
}
int main(){
    int size=5;
    int arr[size];
    insertAtStart(arr,1,size);
    // insertAtStart(arr,2,size);
    // insertAtStart(arr,3,size);
    // insertAtStart(arr,4,size);
    insertAtEnd(2,size,arr);
    insertAtEnd(3,size,arr);
    insertAtEnd(4,size,arr);
    insertAtEnd(5,size,arr);
    // insertAtEnd(6,size,arr);
    display(arr);
    cout<<"dlt at end"<<endl;
    removeAtend(arr,size);
    display(arr);
    cout<<"dlt at start"<<endl;
    removeAtstart(arr,size);
    display(arr);
    return 0;
}