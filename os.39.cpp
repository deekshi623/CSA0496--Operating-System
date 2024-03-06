#include <stdio.h>
#include <stdlib.h>

void cscan(int request[], int n, int head, int direction) {
    int totalSeek = 0;
    int current = head;

    int maxSeek = 199;  // assuming disk size is 200

    printf("Seek sequence using C-SCAN: ");

    if (direction == 0) {
        // Moving towards the right
        for (int i = head; i <= maxSeek; i++) {
            printf("%d ", i);
            totalSeek += abs(current - i);
            current = i;
        }
        // Move to the beginning (0) in a circular manner
        printf("0 ");
        totalSeek += abs(current - 0);
        current = 0;
    } else {
        // Moving towards the left
        for (int i = head; i >= 0; i--) {
            printf("%d ", i);
            totalSeek += abs(current - i);
            current = i;
        }
        // Move to the end (maxSeek) in a circular manner
        printf("%d ", maxSeek);
        totalSeek += abs(current - maxSeek);
        current = maxSeek;
    }

    printf("\nTotal seek distance using C-SCAN: %d\n", totalSeek);
}

int main() {
    int n, head, direction;

    printf("Enter the number of disk requests: ");
    scanf("%d", &n);

    int request[n];

    printf("Enter the disk request sequence:\n");
    for (int i = 0; i < n; i++) {
        printf("Request %d: ", i + 1);
        scanf("%d", &request[i]);
    }

    printf("Enter the initial position of the disk head: ");
    scanf("%d", &head);

    printf("Enter the direction (0 for left, 1 for right): ");
    scanf("%d", &direction);

    cscan(request, n, head, direction);

    return 0;
}
