/*C++ code for tree traversal using preorder and postorder techniques
preorder: root -> left subtree -> right subtree
postorder: left subtree -> right subtree -> root */

#include<bits/stdc++.h>
using namespace std;
//structure of a node in the tree
struct node
{
    int val;
    struct node *left, *right;
    node(int val){
        this->val=val;
        left=right=NULL;
    } 
};

void preorder(struct node *root){
    if(root==NULL)
        return;
    cout<<root->val<<"\t";
    preorder(root->left);
    preorder(root->right);
}

void postorder(struct node *root){
    if(root==NULL)
        return;
    preorder(root->left);
    preorder(root->right);
    cout<<root->val<<"\t";
}

int main(){
    /*
            0
           / \
          1   2
         / \ / \
        3  4 5  6
    */
    struct node *root= new node(0);
    root->left=new node(1);
    root->right=new node(2);
    root->left->left=new node(3);
    root->left->right=new node(4);
    root->right->left=new node(5);
    root->right->right=new node(6);

    cout<<"\nPreorder traversal: \n";
    preorder(root);

    cout<<"\nPostorder traversal: \n";
    postorder(root);

    return 0;

}
