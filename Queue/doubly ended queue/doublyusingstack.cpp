#include <iostream>
using namespace std;

class MyClass {
private:
    static const int size = 5;
    int arr[size]; 
    int f;
    int r;
public:
    MyClass() {
      
        f = -1;
        r = -1;
        cout << "Default constructor called!" << endl;
    }
    bool isEmpty(){
        return (f==-1);
    }
    bool isFull(){
        return ((f==0 && r==size-1 )|| f==r+1);
    }

    void pushStart(int x){
        if (isFull()) // checked for full
        {
            cout<<"queue is full"<<endl;
            return;
        }
        if (f==-1) // checked for empty queue
        {
            f=0;
            r=0;
        }
        else{  // not full nor empty
            if (f==0) // check that wether f is at start if it is, it means either
            // a front element is inserted or rear elemnt has been, so now move 
            {
                f=size-1; // f to the last index;
            }
            else{
                f--;  // it means f is alredy at the other end, so just ak size km kro
            }
        } // jo b case hua f ma ki loc pa add kro
        arr[f]=x;
    }

    void pushback(int x){
        if (isFull())
        {
            cout<<"queue is full"<<endl;
            return;
        }
        if (f==-1)
        {
            f=0;
            r=0;
        }
        else{
            if (r==size-1)
            {
                r=0;
            }
            else{
                r++;
            }
        }
        arr[r]=x;
    }
    void removestart(){
        if (isEmpty())
        {
            cout<<"queue is empty"<<endl;
            return;
        }
        if (f==r)
        {
            f=r=-1;
        }
        else if(f==size-1){
            f=0;
        }else{
            f++;
        }
        
    }
    void removeEnd(){
        if (isEmpty())
        {
            cout<<"queue is empty"<<endl;
            return;
        }
        if (f==r)
        {
            f=r=-1;
        }
        else if( r==0){
            r=size-1;
        }else{
            r--;
        }
        
    }

    void display(){
        if (isEmpty())
        {
            cout<<"queue is empty"<<endl;
            return;
        }
        if (f<=r)
        {
            cout<<"The elements in the queue are: "<<endl;
            for (int i = f; i <= r; i++)
            {
                cout<<arr[i]<<" | ";
            }
        }
        else{
            if (r<f)
            {
                cout<<"The elements in the queue are: "<<endl;
                for (int i = f; i < size; i++)
                {
                cout<<arr[i]<<" | ";    
                }
                f=0;
                for ( int i = f; i <=r; i++)
                {
                    cout<<arr[i]<<" | ";
                }
            }
   
        }
    }
};



int main(){
    
    MyClass dq;
    // dq.pushStart(5);
    // dq.pushStart(6);
    // dq.pushback(7);
    // dq.pushStart(8);
    // dq.pushback(9);
    // dq.display();
    
    // cout<<dqueues.isFull();
    dq.pushStart(5);
    dq.pushStart(6);
    dq.pushback(7);
    dq.pushStart(8);
    dq.pushback(9);
    // dq.display(); // Expected queue: 8 6 5 7 9

    // Removing elements from both ends
    dq.removestart();
    dq.removeEnd();
    // dq.display(); // Expected queue after removals: 6 5 7

    // // Further additions to test wraparound
    dq.pushback(10);
    dq.pushback(11);
    // dq.display(); // Expected queue with wraparound: 6 5 7 10 11

    // // Queue should be full now
    // dq.pushback(12); // Should indicate queue is full
    dq.removestart();
    // dq.display(); // Expected queue: 5 7 10 11
    dq.pushStart(12); // Adding at start
    dq.display(); // Expected queue: 12 5 7 10 11

    return 0;
}
    
