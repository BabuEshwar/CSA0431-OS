#include <stdio.h>

void firstFit(int blockSize[], int blocks, int processSize[], int processes);
void bestFit(int blockSize[], int blocks, int processSize[], int processes);
void worstFit(int blockSize[], int blocks, int processSize[], int processes);

int main() {
    int blockSize[10], processSize[10], blocks, processes, choice;

    // Input memory block sizes
    printf("Enter the number of memory blocks: ");
    scanf("%d", &blocks);
    printf("Enter the sizes of the memory blocks:\n");
    for (int i = 0; i < blocks; i++) {
        printf("Block %d: ", i + 1);
        scanf("%d", &blockSize[i]);
    }

    // Input process sizes
    printf("Enter the number of processes: ");
    scanf("%d", &processes);
    printf("Enter the sizes of the processes:\n");
    for (int i = 0; i < processes; i++) {
        printf("Process %d: ", i + 1);
        scanf("%d", &processSize[i]);
    }

    // Choose the memory allocation strategy
    printf("Choose memory allocation strategy:\n");
    printf("1. First Fit\n");
    printf("2. Best Fit\n");
    printf("3. Worst Fit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            firstFit(blockSize, blocks, processSize, processes);
            break;
        case 2:
            bestFit(blockSize, blocks, processSize, processes);
            break;
        case 3:
            worstFit(blockSize, blocks, processSize, processes);
            break;
        default:
            printf("Invalid choice!\n");
            break;
    }

    return 0;
}

void firstFit(int blockSize[], int blocks, int processSize[], int processes) {
    int allocation[processes];
    for (int i = 0; i < processes; i++) {
        allocation[i] = -1;
    }

    for (int i = 0; i < processes; i++) {
        for (int j = 0; j < blocks; j++) {
            if (blockSize[j] >= processSize[i]) {
                allocation[i] = j;
                blockSize[j] -= processSize[i];
                break;
            }
        }
    }

    printf("First Fit Allocation:\n");
    printf("Process No.\tProcess Size\tBlock No.\n");
    for (int i = 0; i < processes; i++) {
        printf("%d\t\t%d\t\t", i + 1, processSize[i]);
        if (allocation[i] != -1)
            printf("%d\n", allocation[i] + 1);
        else
            printf("Not Allocated\n");
    }
}

void bestFit(int blockSize[], int blocks, int processSize[], int processes) {
    int allocation[processes];
    for (int i = 0; i < processes; i++) {
        allocation[i] = -1;
    }

    for (int i = 0; i < processes; i++) {
        int bestIndex = -1;
        for (int j = 0; j < blocks; j++) {
            if (blockSize[j] >= processSize[i]) {
                if (bestIndex == -1 || blockSize[j] < blockSize[bestIndex]) {
                    bestIndex = j;
                }
            }
        }
        if (bestIndex != -1) {
            allocation[i] = bestIndex;
            blockSize[bestIndex] -= processSize[i];
        }
    }

    printf("Best Fit Allocation:\n");
    printf("Process No.\tProcess Size\tBlock No.\n");
    for (int i = 0; i < processes; i++) {
        printf("%d\t\t%d\t\t", i + 1, processSize[i]);
        if (allocation[i] != -1)
            printf("%d\n", allocation[i] + 1);
        else
            printf("Not Allocated\n");
    }
}

void worstFit(int blockSize[], int blocks, int processSize[], int processes) {
    int allocation[processes];
    for (int i = 0; i < processes; i++) {
        allocation[i] = -1;
    }

    for (int i = 0; i < processes; i++) {
        int worstIndex = -1;
        for (int j = 0; j < blocks; j++) {
            if (blockSize[j] >= processSize[i]) {
                if (worstIndex == -1 || blockSize[j] > blockSize[worstIndex]) {
                    worstIndex = j;
                }
            }
        }
        if (worstIndex != -1) {
            allocation[i] = worstIndex;
            blockSize[worstIndex] -= processSize[i];
        }
    }

    printf("Worst Fit Allocation:\n");
    printf("Process No.\tProcess Size\tBlock No.\n");
    for (int i = 0; i < processes; i++) {
        printf("%d\t\t%d\t\t", i + 1, processSize[i]);
        if (allocation[i] != -1)
            printf("%d\n", allocation[i] + 1);
        else
            printf("Not Allocated\n");
    }
}
