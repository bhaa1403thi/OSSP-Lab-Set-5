
#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <sys/wait.h>

int main() {
    pid_t pid = fork();

    if (pid < 0) {
        perror("fork");
        return 1;
    }

    if (pid == 0) {
        printf("Child process started. PID = %d\n", getpid());
        fflush(stdout);

        while (1)
            pause();
    } else {
        sleep(1);
        printf("Parent sending SIGTERM to child.\n");

        if (kill(pid, SIGTERM) == -1) {
            perror("kill");
            return 1;
        }

        int status;
        waitpid(pid, &status, 0);

        if (WIFSIGNALED(status)) {
            printf("Child terminated by signal %d.\n",
                   WTERMSIG(status));
        }
    }

    return 0;
}
