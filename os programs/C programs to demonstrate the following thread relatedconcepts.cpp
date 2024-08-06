#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define NUM_THREADS 3

void *thread_function(void *thread_id) {
    long tid = (long)thread_id;
    printf("Thread %ld created.\n", tid);
    pthread_exit(NULL);
}

int main() {
    pthread_t threads[NUM_THREADS];
    int i;
    int ret;

    for (i = 0; i < NUM_THREADS; i++) {
        ret = pthread_create(&threads[i], NULL, thread_function, (void *)(long)(i + 1));
        if (ret != 0) {
            perror("Failed to create thread");
            exit(EXIT_FAILURE);
        }
    }

    for (i = 0; i < NUM_THREADS; i++) {
        ret = pthread_join(threads[i], NULL);
        if (ret != 0) {
            perror("Failed to join thread");
            exit(EXIT_FAILURE);
        }
        printf("Thread %d terminated.\n", i + 1);
    }

    return 0;
}

