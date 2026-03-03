// Convert Infix Expression to Postfix Expression
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define N 100

char stack[N];
int top = -1;

void push(char c){
    if(top == N - 1){
        printf("Stack Overflow\n");
        return;
    }
    top++;
    stack[top] = c;
}

char pop(){
    if(top == -1){
        printf("Stack Underflow\n");
        return '\0';
    }
    char c = stack[top];
    top--;
    return c;
}

char peek(){
    if(top == -1)
        return '\0';
    return stack[top];
}

int precedence(char c){
    if(c == '^')
        return 3;
    if(c == '*' || c == '/')
        return 2;
    if(c == '+' || c == '-')
        return 1;
    return 0;
}

int isOperator(char c){
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '^');
}

void infixToPostfix(char *infix, char *postfix){
    int j = 0;
    for(int i = 0; infix[i] != '\0'; i++){
        char c = infix[i];

        // If operand, add to output
        if(isalnum(c)){
            postfix[j++] = c;
        }
        // If '(', push to stack
        else if(c == '('){
            push(c);
        }
        // If ')', pop until '('
        else if(c == ')'){
            while(top != -1 && peek() != '('){
                postfix[j++] = pop();
            }
            pop(); // Remove '('
        }
        // If operator
        else if(isOperator(c)){
            while(top != -1 && precedence(peek()) >= precedence(c) && c != '^'){
                postfix[j++] = pop();
            }
            push(c);
        }
    }
    // Pop remaining operators
    while(top != -1){
        postfix[j++] = pop();
    }
    postfix[j] = '\0';
}

int main(){
    char infix[N], postfix[N];

    printf("Enter infix expression: ");
    scanf("%s", infix);

    infixToPostfix(infix, postfix);

    printf("Postfix expression: %s\n", postfix);

    return 0;
}
