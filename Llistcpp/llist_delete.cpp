# include <iostream>
using namespace std;

struct Node {
    int data;
    Node * next;
};
struct Node* head = NULL;
int count =0;

void deleteFromBeginning(){
    if (head == NULL)
    {
        cout<<"list is alredy empty";
        return;
    }else{
        head= head->next;
        count--;
    } 
};
void deleteFromEnd(){
    Node * t= new Node();
    t=head;
    if (head == NULL)
    {
        cout<<"list is alredy empty";
        return;
    }else{
        while (t->next->next!=NULL)
        {
            t=t->next;
        }
        t->next=NULL;   
        count--;   
    }
};
void dlt_anyloc(int l){
    Node * t= new Node();
    t=head;
    if (head == NULL)
        
    {
        cout<<"list is alredy empty";
        return;
     }
     else{
        for (size_t i = 1; i < l; i++)
        {
            t=t->next;
        }
        t->next=t->next->next;
        count--;
     }
}

 void insertAtEnd(int a){
        Node * tail = new Node();
        tail=head;
        Node * temp = new Node();
        temp->data=a;
        temp->next=NULL;
        if (head==NULL){
            head=temp;
            count++;
        }else
        {
            while (tail->next!=NULL)
            {
                tail=tail->next;
            }
            tail->next=temp;
                temp=tail;
                count++;
        }
        
     };
     
        void insertAtBeginning(int x){
        Node*temp = new Node();
        temp->data=x;
        temp->next=NULL;
        if(head == NULL){
            head=temp;
            count++;
        }else{
            temp->next=head;
            head=temp;
            count++;
        }
     };
     void insert_anylocation(int x,int j){
        Node * temp = new Node();
        Node * t= new Node();
        t=head;
        temp->data=x;
        temp->next=NULL;
        if (head==NULL)
        {
            head=temp;
            count++;
        }else{
           for (size_t i = 1; i < 2; i++)
           {
             t= t->next;
           }
            temp->next=t->next;
            t->next=temp;
            count++;
        }
        
     };
     void display(){
        Node*temp = new Node();
        temp=head;
        while (temp!=NULL)
        {
             cout<<temp->data<<"\n";
             temp=temp->next;
        }
     };
     int main(){
        int choice, value;
       do {
        cout << "\n--- Menu ---\n";
        cout << "1. Insert at Beginning\n";
        cout << "2. Insert at End\n";
        cout << "3. Delete from Beginning\n";
        cout << "4. Delete from End\n";
        cout << "5. Display List\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to insert at beginning: ";
                cin >> value;
                insertAtBeginning(value);
                break;
            case 2:
                cout << "Enter value to insert at end: ";
                cin >> value;
                insertAtEnd(value);
                break;
            case 3:
                deleteFromBeginning();
                break;
            case 4:
                deleteFromEnd();
                break;
            case 5:
                display();
                break;
            case 6:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice! Please try again.\n";
        }
    } while (choice != 6);
        return 0;
     }

