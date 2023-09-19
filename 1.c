/*
============================================================================
Name : 1.c
Author : Harshilkumar Buha
Description : Create the following types of a files using (i) shell command (ii) system call
a. soft link (symlink system call)
b. hard link (link system call)
c. FIFO (mkfifo Library Function or mknod system call)
Date : 27th aug, 2023.
============================================================================
*/
#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>

int main()
{
    int softlink = symlink("dest.txt","softlink_1");
    if(softlink<0)
    {
        perror("failed");
        return -1;
    }

    int fifo = mknod("fifo_1",S_IFIFO,0);
    if(fifo<0)
    {
        perror("failed");
        return -1;
    }
       
    int hardlink = link("dest.txt","hardlink_1");
    if(hardlink<0)
    {
            perror("failed");
            return -1;
    }
    return 0;
}
/*compile and run*/