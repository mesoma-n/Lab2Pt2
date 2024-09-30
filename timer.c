#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <time.h>

int alarm_count = 0;
time_t start_time;

void handler(int signum) {
    printf("Hello World!\n");
    alarm_count++;
    alarm(1);
}

void sigint_handler(int signum) {
    time_t end_time;
    end_time = time(NULL);
    printf("\nTotal execution time: %ld seconds\n", end_time - start_time);
    printf("Total alarms received: %d\n", alarm_count);
    exit(0);
}

int main(int argc, char *argv[]) {
    start_time = time(NULL);
    
    signal(SIGALRM, handler);
    signal(SIGINT, sigint_handler);
    alarm(1);

    while (1);

    return 0;
}