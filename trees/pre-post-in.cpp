#include<iostream>
using namespace std;

struct Node{
    int data;
    Node *left = NULL;
    Node *right = NULL;
};

Node* createnode(int value){
    Node *newnode = new Node;
    newnode->data = value;
    newnode->left = NULL;
    newnode->right = NULL;
    return newnode;
}

void inorder(Node *root){
    if(root == NULL) return;
    inorder(root->left);
    cout << "The Root data is: " << root->data << endl; // LEFT, ROOT, RIGHT
    inorder(root->right);
}

void preorder(Node *root){
    if(root == NULL) return;
    cout << "The Root data is: " << root->data << endl; // ROOT, LEFT, RIGHT
    preorder(root->left);
    preorder(root->right);
}

void postorder(Node *root){
    if(root == NULL) return;
    postorder(root->left);
    postorder(root->right);
    cout << "The Root data is: " << root->data << endl; // LEFT, RIGHT, ROOT
}

int main(){
    int a;

    Node *root = createnode(10);
    root->left = createnode(20);
    root->right = createnode(30);
    root->left->left = createnode(40);
    root->left->right = createnode(50);
    root->right->left = createnode(35);
    root->right->right = createnode(41);

    cout << "Enter 1 for preorder, 2 for post, and 3 for inorder traversal: ";
    cin >> a;

    switch(a){
        case 1:
            preorder(root);
            break;
        case 2:
            postorder(root);
            break;
        case 3:
            inorder(root);
            break;
        default:
            cout << "Invalid choice";
    }

    return 0;
}