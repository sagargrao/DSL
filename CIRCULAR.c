#include<stdio.h>
#include<stdlib.h>
#define max 5

char cq[max];
int front = -1, rear = -1;

void enqueue(char val) {
    if (front == (rear + 1) % max) {
        printf("Circular Queue is FULL\n");
    }
    else {
        if (front == -1) {
            front = rear = 0;
        }
        else {
            rear = (rear + 1) % max;
        }
        cq[rear] = val;
        printf("Inserted %c\n", val);
        printf("Rear=%d Front=%d\n", rear, front);
    }
}

void dequeue() {
    if (front == -1) {
        printf("Circular Queue is EMPTY\n");
    }
    else {
        printf("Deleted element is %c\n", cq[front]);
        cq[front]='-';

        
        
            front = (front + 1) % max;
        
        printf("Rear=%d Front=%d\n", rear, front);
    }
}

void display() {
    if (front == -1) {
        printf("Circular Queue is EMPTY\n");
    }
    else {
        printf("Queue elements: ");
        for (int i = 0;i<max;i++) {
            printf("%c ", cq[i]);
        }
}
}
int main() {
    int choice;
    char val;

    while (1) {
        printf("\n1.Enqueue\n2.Dequeue\n3.Display\n4.Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the value: ");
                scanf(" %c", &val);
                enqueue(val);
                break;

            case 2:
                dequeue();
                break;

            case 3:
                display();
                break;

            case 4:
                exit(0);

            default:
                printf("Invalid choice\n");
        }
    }
}
