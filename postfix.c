#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>

int stack[20];
int top = -1;

void push(int value) {
    stack[++top] = value;
}

int pop() {
    return stack[top--];
}

void postfix() {
    char postfix[20];
    int i, op1, op2;

    printf("Enter the postfix expression: ");
    scanf("%s", postfix);

    for (i = 0; postfix[i] != '\0'; i++) {

        // Operand
        if (isdigit(postfix[i])) {
            push(postfix[i] - '0');
        }

        // Operator
        else {
            op2 = pop();
            op1 = pop();

            switch (postfix[i]) {
                case '+': push(op1 + op2); break;
                case '-': push(op1 - op2); break;
                case '*': push(op1 * op2); break;
                case '/': push(op1 / op2); break;
                case '%': push(op1 % op2); break;
                case '^': push(pow(op1, op2)); break;
            }
        }
    }

    printf("The result is : %d\n", stack[top]);
    printf("%s",postfix);}

int main() {
    postfix();
    return 0;
}
