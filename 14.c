/*
============================================================================
Name : 14.c
Author : Harshilkumar Buha
Description : Write a program to find the type of a file.
a. Input should be taken from command line.
b. program should be able to identify any type of a file.
Date: 29th aug, 2023.
============================================================================
*/
#include<stdio.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<unistd.h>
int main(int argc, char *argv[])
{
    if(argc!=2)
    {
        printf("less arguments");
        return 1;
    }
    struct stat f_stat;
    if(stat(argv[1],&f_stat)==-1)
    {
        perror("stat");
        return 2;
    }
    int k = f_stat.st_mode;
    printf("%d\n",k);
    if (S_ISREG(k)) {
        printf("%s is a regular file.\n", argv[1]);
    } else if (S_ISDIR(k)) {
        printf("%s is a directory.\n", argv[1]);
    } else if (S_ISCHR(k)) {
        printf("%s is a character device.\n", argv[1]);
    } else if (S_ISBLK(k)) {
        printf("%s is a block device.\n", argv[1]);
    } else if (S_ISFIFO(k)) {
        printf("%s is a FIFO (named pipe).\n", argv[1]);
    } else if (S_ISLNK(k)) {
        printf("%s is a symbolic link.\n", argv[1]);
    } else if (S_ISSOCK(k)) {
        printf("%s is a socket.\n", argv[1]);
    } else {
        printf("Cannot determine the type of %s.\n", argv[1]);
    }
    return 0;
}
/*compile and run*/