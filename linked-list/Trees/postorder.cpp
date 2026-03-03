#include<iostream>
using namespace std;
struct Node{
    int data;
    Node* left=NULL;
    Node* right=NULL;
};
Node *createnode(int value){
    Node *newnode=new Node;
    newnode->data=value;
    newnode->right=NULL;
    newnode->left=NULL;
    return newnode;
}
void preorder(Node* root){
    if(root==NULL) return;
    cout<<"Root Data is:"<<root->data<<endl;
    
    preorder(root->left);
    preorder(root->right);
}
int main(){
    Node *root=createnode(10);
    root->left=createnode(20);
    root->right=createnode(30);
    root->left->left=createnode(40);
    root->right->right=createnode(50);
    cout<<"Preorder traversal";
    preorder(root);
    return 0;
}