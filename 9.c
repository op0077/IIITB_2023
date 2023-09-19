/*
============================================================================
Name : 9.c
Author : Harshilkumar Buha
Description : Write a program to print the following information about a given file.
a. inode
b. number of hard links
c. uid
d. gid
e. size
f. block size
g. number of blocks
h. time of last access
i. time of last modification
j. time of last change
Date: 29th aug, 2023.
============================================================================
*/
#include<stdio.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<stdlib.h>
#include<sys/sysmacros.h>
#include<time.h>
int main(){
    struct stat sfile;
    stat("f1.txt", &sfile);
    printf("\ninode number:%ld",sfile.st_ino);
    printf("\ntotal number of hard link:%lu", sfile.st_nlink);
    printf("\nuserid:%d", sfile.st_uid);
    printf("\ngroup id:%d", sfile.st_gid);
    printf("\nsize of the file:%ld",sfile.st_size);
    printf("\nblock size:%ld", sfile.st_blksize);
    printf("\ntotal number of blocks:%ld", sfile.st_blocks);
    printf("\ntime of last access:%ld", sfile.st_atime);
    printf("\ntime of las modification:%ld", sfile.st_mtime);
    printf("\ntime of last change:%ld",sfile.st_ctime);
    return 0;
}
/*compile and run*/