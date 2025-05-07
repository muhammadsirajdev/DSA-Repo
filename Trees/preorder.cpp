#include <iostream>
#include<queue>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    // Constructor
    Node(int val) {
        this->data = val;
        left = right = NULL;
    }
};

void preorder(Node*root){
    if (root == NULL)
    {
        return;
    };
    cout<<root->data<<" ";

    preorder(root->left);
    preorder(root->right);
};
void postorder(Node*root){
    if (root == NULL)
    {
        return;
    };

    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<" ";
}
void inorder(Node*root){
    if (root == NULL)
    {
        return;
    };

    inorder(root->left);
     cout<<root->data<<" ";
    inorder(root->right);
    
};
void printLevelOrder(Node* root)
{
    if (root == NULL)
        return;

    queue<Node*> q;
    
    
    q.push(root);
    q.push(NULL);

    while (!(q.empty())) {
        
        Node * curr = q.front();
        q.pop();
        if (curr==NULL)
        {
            if (q.empty())
            {
                return;
            }else{
                q.push(NULL);
                cout<<endl;
            }
            
        }else{
        
        cout << curr->data << " ";
        
        
        if (curr->left != NULL)
            q.push(curr->left);
        
        if (curr->right != NULL)
            q.push(curr->right);
    }
    }
   
};
void printLevelOrder1(Node* root)
{
    if (root == NULL)
        return;

    queue<Node*> q;
    
    
    q.push(root);
   

    while (!(q.empty())) {
        
        Node * curr = q.front();
        q.pop();
       
        cout << curr->data << " ";
        
        if (curr->left != NULL)
            q.push(curr->left);
        
        if (curr->right != NULL)
            q.push(curr->right);
    
    }
   
};
int size(Node* root){
if (root==NULL)
{
    return 0;
}
return size(root->left)+size(root->right)+1;

};
int height(Node * root){
    if (root==NULL)
    {
        return 0;
    }
    return std::max(height(root->left),height(root->right))+1;
};
int maximum(Node *root){
if (root==NULL)
{
    return INT_MIN;
}
    return (std::max(root->data,std::max(maximum(root->left),maximum(root->right))));
};
int minimum(Node*root){
if (root==NULL)
{
    return INT_MAX;
}
    return (std::min(root->data,std::min(minimum(root->left),minimum(root->right))));

};



int main(){
    Node* root= new Node(1);
    root->left=new Node(2);
    root->left->left=new Node(4);
    root->left->right=new Node(5);
    root->left->right->left=new Node(6);
    root->right=new Node(3);
    root->right->left=new Node(7);
    root->right->right=new Node(8);
    root->right->right->left=new Node(9);
    root->right->right->right=new Node(10);

    preorder(root);
    cout<<endl;
    postorder(root);
    cout<<endl;
    inorder(root);
    cout<<endl;
    printLevelOrder(root);
    cout<<endl;
    printLevelOrder1(root);
    cout<<endl;
    int sizes= size(root);
    cout<<sizes;
    cout<<endl;
    int hig= height(root);
    cout<<hig;
    cout<<endl;
    int max= maximum(root);
    cout<<max;
    cout<<endl;
    int min= minimum(root);
    cout<<min;
    return 0;
}

