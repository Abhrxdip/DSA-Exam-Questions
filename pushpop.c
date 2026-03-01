#include<stdio.h>
static int top=-1;
int arr[20];
void push(){
    int x;
    printf("Enter element to push: ");
    scanf("%d",&x);
    if(top==19){
        printf("Overflow");
    }
    else{
        top++;
        arr[top]=x;
    }
}
void pop(){
    int item;
    if(top==-1){
        printf("Underflow");
    }
    item=arr[top];
    printf("the popped element is: %d",item);
    top--;
}
void peek(){
    printf("the top element is: %d", arr[top]);
}
void display(){
    for(int i=0;i<top;i++){
        printf("The %dth elements are %d",i+1,arr);
    }
}
int main(){
    int n;
    
    while(1){
        printf("Enter 1 for push, 2 for pop, 3 for peek, 4 for display");
    scanf("%d",&n);
        switch(n){
            case 1:
            push();
            break;
            case 2:
            pop();
            break;
            case 3:
            peek();
            break;
            case 4:
            display();
        }
    }
    return 0;
}