#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <pthread.h>

void* thread_function(void* arg) {
    printf("Thread is running\n");
    return NULL;
}

int main() {
    pid_t pid;

    printf("----- Fork Example -----\n");
    pid = fork();

    if (pid < 0) {
        printf("Fork failed\n");
        return 1;
    }

    else if (pid == 0) {
        printf("Child Process\n");
        printf("Child PID: %d\n", getpid());

        printf("\n----- Exec Example (ls command) -----\n");
        execlp("ls", "ls", "-l", NULL);

        printf("This line will not execute\n");
    }

    else {
        printf("Parent Process\n");
        printf("Parent PID: %d\n", getpid());
        printf("Child PID: %d\n", pid);

        printf("\n----- Wait Example -----\n");
        wait(NULL);
        printf("Parent resumes after child finishes\n");

        printf("\n----- ps Command using system() -----\n");
        system("ps -aux");

        printf("\n----- Thread Join Example -----\n");
        pthread_t t1;
        pthread_create(&t1, NULL, thread_function, NULL);
        pthread_join(t1, NULL);

        printf("Thread finished execution\n");
    }

    return 0;
}
