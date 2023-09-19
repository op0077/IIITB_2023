/*
============================================================================
Name : 16.c
Author : Harshilkumar Buha
Description : Write a program to perform mandatory locking.
a. Implement write lock
b. Implement read lock
Date: 29th aug, 2023.
============================================================================
*/
#include<fcntl.h>
#include<stdio.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<unistd.h>
int main()
{

    struct flock lock_write;
    struct flock lock_read;
    lock_write.l_start=0;
    lock_write.l_len=0;
    lock_write.l_whence=SEEK_SET;
    lock_write.l_type=F_WRLCK;
    lock_write.l_pid=F_GETFD;
    lock_read.l_start=0;
    lock_read.l_len=0;
    lock_read.l_whence=SEEK_SET;
    lock_read.l_type=F_RDLCK;
    lock_read.l_pid=F_GETFD;
    printf("opening...\n");

    int fd = open("16_demo.txt",O_RDWR|O_CREAT);
    // write(fd,"hi",2);
    printf("opened..");

    if(fd==-1)
    {
        printf("file is not created\n");
    }
    int read = fcntl(fd,F_SETLKW,&lock_read);
    // printf("%d",read);

    if(read==-1)
    {
        printf("file is not locked by readlock\n");
    }
    else
    {
        printf("file is locked by read_lock\n");
        printf("press enter to remove the lock:");
        getchar();
        // lock_read.l_type = F_ULOCK;
        printf("unlocked\n");
        fcntl(fd,F_UNLCK,&lock_read);
    }
    lseek(fd,0L,SEEK_SET);
    int write = fcntl(fd,F_SETLK,&lock_write);
    if(write == -1)
    {
        printf("file is not looked by writelock\n");
    }
    else
    {
        printf("file is locked by write_lock\n");
        printf("press enter to remove the lock:");
        getchar();
        // lock_write.l_type = F_ULOCK;
        printf("unlocked\n");
        fcntl(fd,F_UNLCK,&lock_write);
    }

    
    int w = close(fd);
    if(w==-1)
    {
        printf("file is not closed yet\n");
        return -1;
    }
    return 0;
}
/*compile */
/*run in 3 terminal*/
/*can apply many read lock if write lock is to applied already*/
/*to apply write lock we need unlock all the read lock first*/