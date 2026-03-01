#include<stdio.h>
#include<string.h>
#define MAX 50
char str[MAX];
static int top=-1;
void push(char ch){
    if(top==MAX-1){
        printf("Overflow");
        return;
    }
    else{
        top++;
        str[top]=ch;
    }
}
char pop(){
    char ch;
    if(top==-1){
        printf("Underflow");
    }
    ch=str[top];
    top--;

}
int main(){
    char str[MAX];
    printf("enter a string: ");
    gets(str);
    for(int i=0;i<strlen(str);i++)
        push(str[i]);
    for(int i=0;i<strlen(str);i++)
        str[i]= pop();
    printf("the element is : %d",str);
    return 0;
}