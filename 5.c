/*
============================================================================
Name : 5.c
Author : Harshilkumar Buha
Description : Write a program to create five new files with infinite loop. Execute the program in the background
and check the file descriptor table at /proc/pid/fd.
Date: 28th aug, 2023.
============================================================================
*/
#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
int main(void)
{
    int f1,f2,f3,f4,f5;
    f1 = open("f1",O_CREAT);
    f2 = open("f2",O_CREAT);
    f3 = open("f3",O_CREAT);
    f4 = open("f4",O_CREAT);
    f5 = open("f5",O_CREAT);
    while(1);
    getchar();
}
/*compile and execute in backgroup
check directory proc/pid/fd*/