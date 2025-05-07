#include <iostream>
using namespace std;

class Node

{
    public:
    int data;
    Node*left;
    Node*right;
    int height;
    Node(){};
    Node(int val){
        this->data=val;
        this->left=NULL;
        this->right=NULL;
        this->height=1;
    }
};
class avlpractice{
    public:
    Node* root;
    avlpractice(){
        root=NULL;
    }
    void updateHeight(Node* node)
		{
			if(node==nullptr)
			{
				return;
			}
			
			node->height=1+max(getHeight(node->left),getHeight(node->right));
		}
    int getHeight(Node* node){
        if(node==NULL){
            return 0;
        }
        return node->height;
    }
    Node*rotateRight(Node* root){
        
            Node* p=root;
            Node*c=p->left;
            p->left=c->right;
            c->right=p;
            updateHeight(p);
            updateHeight(c);
            return c;
    }
    Node* rotateLeft(Node* root){
       Node*p=root;
       Node*c=root->right;
       p->right=c->left;
       c->left=p;
       updateHeight(p);
       updateHeight(c);
       return c;
    }
    int getBalanceFactor(Node*root){
        if (root==NULL)
        {
            return 0;
        }else{
            return getHeight(root->left)-getHeight(root->right);
        }
        
    }
    Node* avlroot(Node* root) {
        if (root==NULL)
        {
            return root;
        }else{
            updateHeight(root);
            int balance = getBalanceFactor(root);
            if(balance>1){
                // left heavy
                //2 cases LL and LR
                if (getBalanceFactor(root->left)>=0){
                    return rotateRight(root);
                }else{
                    root->left=rotateLeft(root->left);
                    return rotateRight(root);    
                }
            }
            else if(balance <-1){
                if (getBalanceFactor(root->right)<=0)
                {
                    return rotateLeft(root);
                }else{
                    root->right=rotateRight(root->right);
                    return rotateLeft(root);
                }
            }
        }
        return root;
    };

    Node* insert(Node* root, int val) {
    if (root == NULL) {
        Node* newNode = new Node(val);
        return newNode;
    }
    if (val >= root->data) {
        root->right = insert(root->right, val); 
    } else { 
        root->left = insert(root->left, val);
    }
    return avlroot(root); 
}
void inorder(Node* root)
		{
			if(root)
			{
				inorder(root->left);
				cout<<root->data<<" ";
				inorder(root->right);
			}
		}

};
int main() {
    avlpractice avl;
    avl.root = avl.insert(avl.root, 21);
    avl.root = avl.insert(avl.root, 26);
    avl.root = avl.insert(avl.root, 30);
    avl.root = avl.insert(avl.root, 9);
    avl.root = avl.insert(avl.root, 4);
    avl.root = avl.insert(avl.root, 14);
    avl.root = avl.insert(avl.root, 28);
    avl.root = avl.insert(avl.root, 18);
    avl.root = avl.insert(avl.root, 15);
    avl.root = avl.insert(avl.root, 10);
   

    cout << "Inorder traversal of the constructed AVL tree is: ";
    avl.inorder(avl.root);
    cout << endl;
    cout<<avl.getHeight(avl.root);

    return 0;
}


