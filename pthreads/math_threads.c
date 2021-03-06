
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/msg.h>
#include <sys/wait.h>
#include <sys/syscall.h>
#include <string.h>
#include <pthread.h>

int result = 0;


void *threadHandler(void *ptr) {
    for (int j = 0; j < 1000000; ++j) {
        result++;
}
    pthread_exit(NULL);
    return NULL;
}
int main(int argc, char *argv[]) {
    if (argc == 1) {
        exit(1);
    }

    int THREADS = atoi(argv[1]);
    pthread_t threads[THREADS];

    for (int i = 0; i < THREADS; ++i) {
        pthread_create(&threads[i], NULL, threadHandler, NULL);
    }

    for (int i = 0; i < THREADS; ++i) {
        pthread_join(threads[i], NULL);
    }

    printf("Result is %d\n", result);
    return 0;
}

