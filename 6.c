/*
============================================================================
Name : 6.c
Author : Harshilkumar Buha
Description : Write a program to take input from STDIN and display on STDOUT. Use only read/write system calls
Date: 28th aug, 2023.
============================================================================
*/
#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
int main()
{
    char m[10];
    read(0,m,10); // 0 = standard input from terminal(stdin)
    write(1,m,10); // 1 = standard write from terminal(stdout)
    return 0;

}
/*compile and run*/