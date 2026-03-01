#include<iostream>
using namespace std;

struct Node{
    int data;
    Node *next=NULL;
};

Node *head=NULL;

void push(int x){
    Node* newnode=new Node;
    newnode->data=x;
    newnode->next=head;
    head=newnode;
    cout<<"element pushed: "<<x<<endl;
}

void pop(){
    if(head==NULL) return;
    int number=head->data;
    head=head->next;
}

void peek(){
    cout<<"Topmost element is: "<<head->data;
}

void display(){
    Node *ptr=head;
    if(head==NULL) return;

    while(ptr->next!=NULL){
        cout<<"element: "<<ptr->data;
        ptr=ptr->next;
    }
}

int main(){
    int value,choice;

    while(true){
        cout<<"1 for push, 2 for pop, 3 for peek, 4 for display";
        cin>>choice;

        switch(choice){


        case 1:
            cout<<"enter element to be pushed";
            cin>>value;
            push(value);
            break;

        case 2:
            pop();
            break;

        case 3:
            peek();
            break;

        case 4:
            display();
            break;

        default:
            cout<<"Invalid choice";
            break;
        }
    }
    return 0;
}