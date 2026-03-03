// input nebo as a character...
// for loop cholbe upto null character
// if str[i]== space, continue
// switch korbo str[i] ke
// operator perform..
// akdom last e print top element of stack
// sum er jonne:
// 1)op1=stack[top];
// 2)top--;
// 3)op2=stack[top];
// 4)top--;
// 5)operation
// 6)add(op2+op1)
// 7)stack[top]=res
// power er joone:
//  op1 = stack[top];
//     top--;
//     op2 = stack[top];
//     top--;
//     for(int i = 0; i < op1; i++){
//         res = res * op2;
//     }
//     top++;
//     stack[top] = res;
// }

#include<stdio.h>
#define N 50

int stack[N];
int top = -1;

void sum(){
    int res, op1, op2;
    op1 = stack[top];
    top--;
    op2 = stack[top];
    top--;
    res = op1 + op2;
    top++;
    stack[top] = res;
}

void diff(){
    int res, op1, op2;
    op1 = stack[top];
    top--;
    op2 = stack[top];
    top--;
    res = op2 - op1;
    top++;
    stack[top] = res;
}

void mult(){
    int res, op1, op2;
    op1 = stack[top];
    top--;
    op2 = stack[top];
    top--;
    res = op2 * op1;
    top++;
    stack[top] = res;
}

void divide(){
    int res, op1, op2;
    op1 = stack[top];
    top--;
    op2 = stack[top];
    top--;
    res = op2 / op1;
    top++;
    stack[top] = res;
}

void power(){
    int op1, op2, res = 1;
    op1 = stack[top];
    top--;
    op2 = stack[top];
    top--;
    for(int i = 0; i < op1; i++){
        res = res * op2;
    }
    top++;
    stack[top] = res;
}

int main(){
    char str[50];
    printf("Enter postfix expression: ");
    scanf(" %[^\n]", str);

    for(int i = 0; str[i] != '\0'; i++){
        if(str[i] == ' ')
            continue;

        switch(str[i]){
            case '+':
                sum();
                break;
            case '-':
                diff();
                break;
            case '*':
                mult();
                break;
            case '/':
                divide();
                break;
            case '^':
                power();
                break;
            default:
                top++;
                stack[top] = str[i] - '0';
        }
    }

    printf("Result: %d", stack[top]);
    return 0;
}