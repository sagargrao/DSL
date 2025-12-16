#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Calender {
    char *name;
    char *event;
    int date;
};

struct Calender *c;

void create() {
    c = (struct Calender *)malloc(7 * sizeof(struct Calender));
}

void read() {
    char buffer[50];

    for (int i = 0; i < 7; i++) {

        printf("\nEnter Day: ");
        scanf("%s", buffer);
        (c + i)->name = (char *)malloc(strlen(buffer) + 1);
        strcpy((c + i)->name, buffer);

        printf("Enter Date: ");
        scanf("%d", &(c + i)->date);

        printf("Enter Event: ");
        scanf("%s", buffer);
        (c + i)->event = (char *)malloc(strlen(buffer) + 1);
        strcpy((c + i)->event, buffer);
    }
}

void display() {
    printf("\n-------------------------------------------");
    printf("\nDAY\tDATE\tEVENT");
    printf("\n-------------------------------------------");

    for (int i = 0; i < 7; i++) {
        printf("\n%s\t%d\t%s",
               (c + i)->name,
               (c + i)->date,
               (c + i)->event);
    }
}

int main() {
    create();
    read();
    display();
    return 0;
}
