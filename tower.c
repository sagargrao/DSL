#include <stdio.h>

void towerofhanoi(int n, char source, char dest, char temp);

int main() {
    int n;
    printf("Enter the number of disks: ");
    scanf("%d", &n);

    towerofhanoi(n, 'S', 'D', 'T');
    return 0;
}

void towerofhanoi(int n, char source, char dest, char temp) {

    // Base condition
    if (n == 1) {
        printf("Move disk 1 from %c to %c\n", source, dest);
        return;
    }

    // Move n-1 disks from source to temp
    towerofhanoi(n - 1, source, temp, dest);

    // Move nth disk from source to destination
    printf("Move disk %d from %c to %c\n", n, source, dest);

    // Move n-1 disks from temp to destination
    towerofhanoi(n - 1, temp, dest, source);
}
