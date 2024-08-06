#include <stdio.h>

#define MAX_BLOCKS 100

int memory[MAX_BLOCKS];
int processSize[MAX_BLOCKS];

void initializeMemory(int size);
int worstFit(int size);
void deallocateMemory(int blockIndex, int size);
void displayMemoryStatus(int totalBlocks);

int main() {
    int memorySize, choice, procSize, blockIndex;
    printf("Enter the size of memory: ");
    scanf("%d", &memorySize);
    initializeMemory(memorySize);
    while (1) {
        printf("\n1. Allocate Memory\n2. Deallocate Memory\n3. Display Memory Status\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter the size of the process: ");
                scanf("%d", &procSize);
                blockIndex = worstFit(procSize);
                if (blockIndex != -1) {
                    printf("Memory allocated successfully at block %d\n", blockIndex);
                } else {
                    printf("Memory allocation failed. No suitable block found.\n");
                }
                displayMemoryStatus(MAX_BLOCKS);
                break;
            case 2:
                printf("Enter the block index to deallocate: ");
                scanf("%d", &blockIndex);
                if (blockIndex >= 0 && blockIndex < MAX_BLOCKS) {
                    deallocateMemory(blockIndex, processSize[blockIndex]);
                    printf("Memory deallocated successfully from block %d\n", blockIndex);
                } else {
                    printf("Invalid block index.\n");
                }
                displayMemoryStatus(MAX_BLOCKS);
                break;
            case 3:
                displayMemoryStatus(MAX_BLOCKS);
                break;
            case 4:
                return 0;
            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }
    }
    return 0;
}

void initializeMemory(int size) {
    for (int i = 0; i < MAX_BLOCKS; i++) {
        memory[i] = size;
        processSize[i] = 0; 
    }
}

int worstFit(int size) {
    int maxBlockSize = -1;
    int blockIndex = -1;
    for (int i = 0; i < MAX_BLOCKS; i++) {
        if (memory[i] >= size && memory[i] > maxBlockSize) {
            maxBlockSize = memory[i];
            blockIndex = i;
        }
    }
    if (blockIndex != -1) {
        memory[blockIndex] -= size;
        processSize[blockIndex] = size; 
    }
    return blockIndex;
}

void deallocateMemory(int blockIndex, int size) {
    memory[blockIndex] += size;
    processSize[blockIndex] = 0; 
}

void displayMemoryStatus(int totalBlocks) {
    printf("Memory Status:\n");
    for (int i = 0; i < totalBlocks; i++) {
        printf("Block %d: %d\n", i, memory[i]);
    }
}

