#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

int flag = 0;

void handler(int signum) {
    printf("Hello World!\n");
    flag = 1;
}

int main(int argc, char *argv[]) {
    signal(SIGALRM, handler);
    alarm(5);

    while (1) {
        if (flag) {
            printf("Turing was right!\n");
            flag = 0;
            alarm(5);
        }
    }

    return 0;
}
