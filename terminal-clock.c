/*
Purpose: Print local time once per second
Documentation used:
    - https://en.cppreference.com/w/c/chrono/time
    - https://en.cppreference.com/w/c/chrono/localtime
    - https://en.cppreference.com/w/c/program/signal

*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h> // time(), localtime(), strftime(), struct tm
#include <unistd.h> // sleep()
#include <signal.h> // SIGINT, signal()

void signalHandler(int signal) {
    printf("\nProgram ended\n");
    exit(1);
}

void clears(void) {
    printf("\e[1;1H\e[2J");
}

int main(void) {
    time_t varTime = time(NULL);
    struct tm *pTime;
    char buf[9];
    int on;

    signal(SIGINT, signalHandler);

    printf("Press Ctrl-C at any point to exit the program\n");
    sleep(3);
    clears();

    while (on) {
        varTime = time(NULL) + 1;
        pTime = localtime(&varTime);
        
        strftime(buf, sizeof(buf), "%X", pTime);
        printf("*%s\n", buf);
        sleep(1);
        clears();
    }

    return 0;
}
