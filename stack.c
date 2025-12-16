#include <stdio.h>
#include <stdlib.h>

#define max 5

int stack[max];
int top = -1;

/* Push operation */
void push(int val) {
    if (top == max - 1) {
        printf("Stack Overflow\n");
    } else {
        stack[++top] = val;
    }
}

/* Pop operation */
int pop() {
    if (top == -1) {
        printf("Stack Underflow\n");
        return -1;
    } else {
        return stack[top--];
    }
}

/* Palindrome check using stack */
void palindrome() {
    int num, temp, rem;
    int rev = 0;

    /* RESET STACK BEFORE USE */
    top = -1;

    printf("Enter the number: ");
    scanf("%d", &num);

    temp = num;

    /* Push digits into stack */
    while (num != 0) {
        rem = num % 10;
        push(rem);
        num /= 10;
    }

    /* Pop digits to form reverse number */
    while (top != -1) {
        rev = rev * 10 + pop();
    }

    if (temp == rev)
        printf("The number is a Palindrome\n");
    else
        printf("The number is NOT a Palindrome\n");
}

/* Display stack */
void display() {
    if (top == -1) {
        printf("Stack is empty\n");
    } else {
        printf("Stack elements are:\n");
        for (int i = top; i >= 0; i--) {
            printf("%d\n", stack[i]);
        }
    }
}

int main() {
    int choice, val;

    while (1) {
        printf("\n1.Push\n2.Pop\n3.Display\n4.Palindrome Check\n5.Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the value to be pushed: ");
                scanf("%d", &val);
                push(val);
                break;

            case 2:
                val = pop();
                if (val != -1)
                    printf("Popped element is %d\n", val);
                break;

            case 3:
                display();
                break;

            case 4:
                palindrome();
                break;

            case 5:
                exit(0);

            default:
                printf("Invalid choice\n");
        }
    }
}
