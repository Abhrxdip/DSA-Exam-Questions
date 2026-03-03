// TREE:
//           50
//          /  \
//        30    90
//       /  \
//     10    40
//       \
//        21
#include<iostream>
using namespace std;
struct Node{
    int data;
    Node*left=NULL;
    Node *right=NULL;
};
Node* createnode(int value){
    Node * newnode=new Node;
    newnode->data=value;
    newnode->right=NULL;
    newnode->left=NULL;
    return newnode;
}
Node *insertnode(Node*root, int value){
    if(root==NULL){ 
        root=createnode(value); 
        return root;
    }
    if(value<root->data){
        root->left=insertnode(root->left,value);
        return root;
    }
    else{
        root->right=insertnode(root->right,value);
        return root;
    }
}
void postorder(Node *root){
    if(root == NULL) return;
    postorder(root->left);
    postorder(root->right);
    cout << "The Root data is: " << root->data << endl; // LEFT, RIGHT, ROOT
}
//height
int max(int a , int b){
    if(a>b) return a;
    else return b;
}
int height(Node *root){
    if(root==NULL) return 0;
    int leftheight=height(root->left);
    int rightheight=height(root->right);
    return max(rightheight,leftheight)+1;
}
//count
int count(Node* root){
    if(root==NULL) return 0;
    int leftcount=count(root->left);
    int rightcount=count(root->right);
    return rightcount+leftcount+1;
}
//FIND MIN: GO LEFT
int findmin(Node *root){
    if(root==NULL) return -1;
    Node *temp=root;
    while(temp->left!=NULL){
        temp=temp->left;
    }
    return temp->data;
}
//FIND MAX:GO RIGHT
int findmax(Node *root){
    if(root==NULL) return -1;
    Node *temp=root;
    while(temp->right!=NULL){
        temp=temp->right;
    }
    return temp->data;
}
int main(){
    // Node *root=insertnode(root, 50);
    // insertnode(root,30);
    // insertnode(root,40);
    // insertnode(root,10);
    // insertnode(root,90);
    // insertnode(root,21);
    // cout<<"The postorder sequence is: "<<endl;
    // postorder(root);
    // this throws an error as root uninitialized
    Node*root=NULL;
    root=insertnode(root, 50);
    insertnode(root,30);
    insertnode(root,40);
    insertnode(root,10);
    insertnode(root,90);
    insertnode(root,21);
    cout<<"The postorder sequence is: "<<endl;
    postorder(root);
    cout<<"Height of the tree is: "<<height(root)<<endl;
    cout<<"number of nodes is: "<<count(root)<<endl;
    cout<<"MINIMUM ELEMENT: " <<findmin(root)<<endl;
    cout<<"MAXIMUM ELEMENT: " <<findmax(root)<<endl;
    return 0;
}