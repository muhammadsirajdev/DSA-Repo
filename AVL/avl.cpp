#include <iostream>
using namespace std;

class Node{
    public:
    int data;
    Node*left;
    Node*right;

    Node(){};
    Node(int d){data=d; left=NULL;right=NULL;}
};

Node * leftrotate(Node *root){
    //right-right case
    Node*p=root;
    Node*c=p->right;
    p->right=c->left;
    c->left=p;

    return c;
}
Node * rightrotate(Node * root){
    //left left case
    Node *p=root;
    Node *c=root->left;
    p->left=c->right;
    c->right=p;
    return c;
}
Node * leftright(Node * root){
    //left right case
    Node *p=root;
    Node *c=p->left;
    Node*g=c->right;

    c->right=g->left;
    p->left=g;
    g->left=c;
    return g;
}
Node* rightleft(Node * root){
    Node* p=root;
    Node*c=p->right;
    Node*g=c->left;

    c->left=g->right;
    p->right=c;
    g->right=c;
    return g;
}
int height(Node *root){
    if (root==NULL)
    {
        return 0;
    }
    int leftheight=height(root->left);
    int rightheight=height(root->right);
    return max(leftheight,rightheight)+1;
    
}
int difference(Node *root) { 
int l_height = height(root->left); 
int r_height = height(root->right); 
int b_factor = l_height - r_height; 
return b_factor; 
} 
Node * balance(Node *t) { 
   int bal_factor = difference(t); 
   if (bal_factor > 1) { 
      if (difference(t->left) > 0) 
         t = leftrotate(t); 
      else 
         t = leftright(t); 
   } else if (bal_factor < -1) { 
      if (difference(t->right) > 0) 
         t = rightleft(t); 
      else 
         t = rightrotate(t); 
   } 
   return t; 
}
Node * root=NULL;
Node * insert(Node*root,int data){
    
    if (root==NULL)
    {
        Node *newnode= new Node(data);
        return newnode;
    }else{
        if (data<root->data)
        {
            root->left= insert(root->left,data);
            root=balance(root);
        }
        else {
            root->right=insert(root->right,data);
            root=balance(root);
        }
    }
    return root;
};


// Node * rotate(Node * root){
//     if (height(root->left)-height(root->right)>1)
//     {
//         //left  case, which further has a case,left-right && lefy-left
//         if (height(root->left->left)-height(root->left->right)>0)
//         {
//         //left left case
//         return rightrotate(root);
//         }
//         if (height(root->left->left)-height(root->left->right)<0)
//         {
//             //left right case , first left rotate then right rotate
//             root->left=leftrotate(root->left);
//             return rightrotate(root);
//         }
//     }
    
    
//     if (height(root->left)-height(root->right)<-1)
//     {
//         //right  case, which further has a case,right-lrft && right-right
//         if (height(root->right->left)-height(root->right->right)<0)
//         {
//         //right right case
//         return leftrotate(root);
//         }
//         if (height(root->right->left)-height(root->right->right)>0)
//         {
//             //right left  case , first right rotate then left rotate
//             root->right=rightrotate(root->right);
//             return leftrotate(root);
//         }
//     }
//     return root;
    
// }

void display(Node * root){
if (root==NULL)
{
   return;
}else{
    display(root->left);
    cout<<root->data<<" | ";
    display(root->right);
}
}
int main(){
   root = insert(root, 5); // Update root
    root = insert(root, 6);
    root = insert(root, 7);
    root = insert(root, 8);
    root = insert(root, 9);
    root = insert(root, 10);
    root = insert(root, 11);
    root = insert(root, 12);
    root = insert(root, 13);
    root = insert(root, 14);
    root = insert(root, 15);

    display(root);
    cout<<endl;
    cout<<height(root);
    cout<<endl;
    
    return 0;
}

