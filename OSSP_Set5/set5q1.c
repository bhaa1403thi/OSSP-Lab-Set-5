
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

int main() {
    int fd[2];
    char message[] = "Hello from parent!";
    char buffer[100];

    if (pipe(fd) == -1) {
        perror("pipe");
        return 1;
    }

    pid_t pid = fork();

    if (pid < 0) {
        perror("fork");
        return 1;
    }

    if (pid == 0) {
        close(fd[1]);

        int n = read(fd[0], buffer, sizeof(buffer) - 1);
        if (n >= 0) {
            buffer[n] = '\0';
            printf("Child received: %s\n", buffer);
        }

        close(fd[0]);
    } else {
        close(fd[0]);
        write(fd[1], message, strlen(message));
        close(fd[1]);
        wait(NULL);
    }

    return 0;
}
