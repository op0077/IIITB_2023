/*
============================================================================
Name : 17_Book_ticket.c
Author : Harshilkumar Buha
Description : Write a program to simulate online ticket reservation. Implement write lock
Write a program to open a file, store a ticket number and exit. Write a separate program, to
open the file, implement write lock, read the ticket number, increment the number and print
the new ticket number then close the file.
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
    struct{
        int ticket_no;
    }ticket;
    struct flock lock;
    int fd = open("ticket.txt",O_RDWR);
    read(fd,&ticket,sizeof(ticket));
    lock.l_type=F_WRLCK;
    lock.l_whence=SEEK_SET;
    lock.l_start=0;
    lock.l_len=0;
    lock.l_pid=getpid();
    printf("before critical\n");
    fcntl(fd,F_SETLKW,&lock);
    printf("ticket no : %d",ticket.ticket_no);
    ticket.ticket_no++;
    lseek(fd,0L,SEEK_SET);
    write(fd,&ticket,sizeof(ticket));
    printf("entered critical section\n");
    printf("enter for unlock : ");
    getchar();
    lock.l_type = F_UNLCK;
    printf("unlocked\n");
    fcntl(fd,F_SETLK,&lock);
    printf("done\n");
    int w = close(fd);
    
    return 0;
}
/*after executing 17_store.c */
/*compilea and run in 2 terminal*/