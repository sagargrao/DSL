#include <stdio.h>
#include <ctype.h>

char stack[20];
int top = -1;

void push(char val) {
    stack[++top] = val;
}

char pop() {
    return stack[top--];
}

int priority(char c) {
    switch (c) {
        case '^':
        case '$': return 3;
        case '*':
        case '/':
        case '%': return 2;
        case '+':
        case '-': return 1;
        default: return 0;
    }
}

void infix_postfix() {
    char infix[20], postfix[20];
    int i, j = 0;

    printf("Enter the infix expression: ");
    gets(infix);

    // ✅ FOR LOOP USED HERE
    for (i = 0; infix[i] != '\0'; i++) {

        // Operand
        if (isalpha(infix[i])) {
            postfix[j++] = infix[i];//Alphabets to postfix
        }

        // Left parenthesis to postfix
        else if (infix[i] == '(') {
            push(infix[i]);
        }

        // Right parenthesis pop
        else if (infix[i] == ')') {
            while (stack[top] != '(') {
                postfix[j++] = pop();
            }
            pop();   // remove '('
        }

        // Operator
        else if(priority(infix[i]) >priority(stack[top])) {
            push(infix[i]);
        
            }
        else{
            postfix[j++] =pop();
            push(infix[i]);
        }
           
        }
    

    // Pop remaining operators
    while (top != -1) {
        postfix[j++] = pop();
    }

    postfix[j] = '\0';

    printf("\nPostfix Expression: %s\n", postfix);

}
int main() {
    infix_postfix();
    return 0;
}
