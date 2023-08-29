#include<stdio.h>
#include<iostream>
#include<sys/types.h>
#include<sys/stat.h>
#include<unistd.h>
using namespace std;
int main(int argc, char *argv[])
{
    if(argc!=2)
    {
        cout<<"less arguments";
        return 1;
    }
    struct stat f_stat;
    if(stat(argv[1],&f_stat)==-1)
    {
        perror("stat");
        return 2;
    }
    if (S_ISREG(f_stat.st_mode)) {
        printf("%s is a regular file.\n", argv[1]);
    } else if (S_ISDIR(f_stat.st_mode)) {
        printf("%s is a directory.\n", argv[1]);
    } else if (S_ISCHR(f_stat.st_mode)) {
        printf("%s is a character device.\n", argv[1]);
    } else if (S_ISBLK(f_stat.st_mode)) {
        printf("%s is a block device.\n", argv[1]);
    } else if (S_ISFIFO(f_stat.st_mode)) {
        printf("%s is a FIFO (named pipe).\n", argv[1]);
    } else if (S_ISLNK(f_stat.st_mode)) {
        printf("%s is a symbolic link.\n", argv[1]);
    } else if (S_ISSOCK(f_stat.st_mode)) {
        printf("%s is a socket.\n", argv[1]);
    } else {
        printf("Cannot determine the type of %s.\n", argv[1]);
    }
    return 0;
}
