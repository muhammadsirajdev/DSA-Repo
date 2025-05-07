# include <iostream>
using namespace std;
struct Node{
    int data;
    Node * next;
};
struct Node * head= NULL;
void insert(int x){
    Node * temp = new Node();
    temp->data=x;
    temp->next=NULL;
    if (head==NULL)
    {
        head = temp;
    }else{
        Node *t=head;
        while (t->next!=NULL)
        {
            t=t->next;
        }t->next=temp;
    }
    
};
void printeven(){
    if (head==NULL)
    {
        cout<<"The linked List is empty";
    }else{
        Node *temp= head;
        while (temp!=NULL)
        {
            if (temp->data%2==0)
            {
                cout<<temp->data;
                temp=temp->next;
            }
            temp=temp->next;
            
        }
         
    }
    
};
int main(){
     int choice, value;
       do {
        cout << "\n--- Menu ---\n";
        cout << "1. Insert element \n";
        cout << "2. Display even :\n";
        cout << "3. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
         switch (choice) {
            case 1:
                cout << "Enter value to insert: ";
                cin >> value;
                insert(value);
                break;
            case 2:
                cout << "display the even Numbers: ";
                printeven();
                break;
            case 3:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice! Please try again.\n";
        }    
}while (choice != 3);
return 0;
}