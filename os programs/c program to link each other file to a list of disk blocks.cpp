#include <stdio.h>
#include <stdlib.h>

#define MAX_BLOCKS 50

int main() {
    int f[MAX_BLOCKS] = {0};  // Array to keep track of allocated blocks
    int p, i, st, len, j, c, a;

    printf("Enter how many blocks are already allocated: ");
    scanf("%d", &p);

    printf("Enter the block numbers already allocated: ");
    for (i = 0; i < p; i++) {
        scanf("%d", &a);
        if (a >= 0 && a < MAX_BLOCKS) {
            f[a] = 1;
        } else {
            printf("Invalid block number %d, skipping...\n", a);
        }
    }

    while (1) {
        printf("Enter index starting block and length: ");
        scanf("%d%d", &st, &len);

        if (st < 0 || st >= MAX_BLOCKS || len <= 0 || st + len > MAX_BLOCKS) {
            printf("Invalid starting block or length. Please try again.\n");
            continue;
        }

        int canAllocate = 1;
        for (j = st; j < st + len; j++) {
            if (f[j] == 1) {
                printf("Block %d is already allocated.\n", j);
                canAllocate = 0;
            }
        }

        if (canAllocate) {
            for (j = st; j < st + len; j++) {
                f[j] = 1;
                printf("%d --------> %d\n", j, f[j]);
            }
        } else {
            printf("Unable to allocate the requested blocks.\n");
        }

        printf("Do you want to enter more files? (Yes - 1 / No - 0): ");
        scanf("%d", &c);
        if (c == 0) {
            break;
        }
    }

    return 0;
}

