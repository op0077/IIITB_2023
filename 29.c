/*
============================================================================
Name : 29.c
Author : Harshilkumar Buha
Description : Write a program to get scheduling policy and modify the scheduling policy (SCHED_FIFO,
SCHED_RR).
Date: 8th sep, 2023.
============================================================================
*/
#include <stdio.h>
#include <stdlib.h>
#include <sched.h>
#include <unistd.h>
#include <errno.h>

int main() {
    int pid=getpid();

    int current_policy = sched_getscheduler(0);
    if (current_policy == -1) {
        perror("Error getting scheduling policy");
        return 1;
    }

    printf("Current scheduling policy: ");
    switch (current_policy) {
        case SCHED_FIFO:
            printf("SCHED_FIFO\n");
            break;
        case SCHED_RR:
            printf("SCHED_RR\n");
            break;
        default:
            printf("Unknown\n");
            break;
    }

    struct sched_param param;
    param.sched_priority = 10; 
    
    if (sched_setscheduler(pid, SCHED_FIFO, &param) == -1) {
        perror("Error");
        return -11;
    }

    printf("Scheduling policy changed to SCHED_FIFO\n");

    int new_policy = sched_getscheduler(getpid());

    if (new_policy == -1) {
        perror("Error getting scheduling policy");
        return 1;
    }

    printf("new scheduling policy: ");
    switch (new_policy) {
        case SCHED_FIFO:
            printf("SCHED_FIFO\n");
            break;
        case SCHED_RR:
            printf("SCHED_RR\n");
            break;
        default:
            printf("Unknown (%d)\n", new_policy);
            break;
    }
  

    return 0;
}
/*compile and run*/