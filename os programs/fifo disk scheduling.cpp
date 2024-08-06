#include <stdio.h>
#include <stdlib.h> 
int main() {
    int n, i, totalHeadMovement = 0, currentPosition;
    printf("Enter the number of disk requests: ");
    scanf("%d", &n);
    int requests[n];
    printf("Enter the initial head position: ");
    scanf("%d", &currentPosition);
    printf("Enter the disk requests:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &requests[i]);
    }
    for (i = 0; i < n; i++) {
        totalHeadMovement += abs(requests[i] - currentPosition);
        currentPosition = requests[i];
    }
    printf("Total head movement: %d\n", totalHeadMovement);
    return 0;
}

