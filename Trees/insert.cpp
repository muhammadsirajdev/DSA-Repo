#include <iostream>
#include<queue>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;
    int height;

    // Constructor
    Node(int val) {
        this->data = val;
        left = right = NULL;
        height=1;
    }
};
int height(Node* node) {
    return (node == nullptr) ? 0 : node->height;
}
// int height(Node *node) {
//     if (node == nullptr)
//         return 0;

//     // compute the depth of left and right subtrees
//     int lDepth = height(node->left);
//     int rDepth = height(node->right);

//     return max(lDepth, rDepth) + 1;
// }

Node * rightrotate(Node*p){
Node*c =p->left;
Node*t=c->right;

c->right=p;
p->left=t;
// Update heights
    p->height = max(height(p->left), height(p->right)) + 1;
    c->height = max(height(c->left), height(c->right)) + 1;

return c;
 };
Node * leftrotate(Node*c){
Node*p =c->right;
Node*t=p->left;

p->left=c;
c->right=t;
c->height = max(height(c->left), height(c->right)) + 1;
    p->height = max(height(p->left), height(p->right)) + 1;

return p;
 };
 Node *rotate(Node* root){
    //apply 4 cases of AVL
    //if height of l-r >1, it means left heavy,now left heavy has 2 cases
    if (height(root->left)-height(root->right)>1)//left heavy
    {
        //1 left-left
        if (height(root->left->left)-height(root->left->right)>0)
        {
            return rightrotate(root);
        }
        //2 left-right
        if (height(root->left->left)-height(root->left->right)<0)
        {
            root->left=leftrotate(root->left);// first left rotate on child
            return rightrotate(root);//the right rotate on original node
        } 
    }
    if (height(root->left)-height(root->right)<-1)//right heavy
    {
        //1 right-right
        if (height(root->right->left)-height(root->right->right)<0)
        {
            return leftrotate(root);
        }
        //2 right-left
        if (height(root->right->left)-height(root->right->right)>0)
        {
            root->right=rightrotate(root->right);// first left rotate on child
            return leftrotate(root);//the right rotate on original node
        } 
    }
    return root;
 };
 Node* insert(Node* root,int val){
    if (root==NULL)
    {
        Node* newNode=new Node(val);
        return newNode;
    }
    if (root->data>val)
    {
        root->left=insert(root->left,val);
    }
    if (root->data<val)
    {
        root->right=insert(root->right,val);
    }
    root->height = max(height(root->left), height(root->right)) + 1;
    return rotate(root);
};



bool searche(Node * root,int val){
    if (root ==NULL)
    {
        return false;
    }if (root->data==val)
    {
       return true;
    }if (root->data>val)
    {
        return searche(root->left,val);
    }else{
        return searche(root->right,val);
    }
    
};
void inorder(Node* root) {
    if (root == NULL) {
        return;
    }
    inorder(root->left);
    cout << root->data << endl;
    inorder(root->right);
}
int main(){
    //  insert(root,10);
    //  insert(root,30);
    //  insert(root,6);
    //  insert(root,30);
    //  insert(root,3);
    //  insert(root,9);
    //  insert(root,15);
    //  insert(root,12);
    //  insert(root,18);
    //  insert(root,25);
    //  insert(root,40);
    //  insert(root,35);
    //  insert(root,50);

    //  inorder(root);
    //  bool x= searche(root,12);
    //  cout<<x<<endl;
    Node* root= NULL;
    for (int i = 0; i < 1000; i++)
    {
        root =insert(root,i);
    }
    
   
     cout<<"The heigt is "<< height(root) <<endl;
}