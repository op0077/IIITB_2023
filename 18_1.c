/*
============================================================================
Name : 18_1.c
Author : Harshilkumar Buha
Description : Write a program to perform Record locking.
a. Implement write lock
b. Implement read lock
Create three records in a file. Whenever you access a particular record, first lock it then modify/access
to avoid race condition.
Date: 29th aug, 2023.
============================================================================
*/
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main(){
	
	int fd = open("18_record.txt", O_RDWR | O_CREAT);
	if(fd == -1)
	{
		printf("file is'n opened");
	}
	else
	{
		printf("enter 3 space separated integer values\n");
		int x,y,z;
        scanf("%d%d%d",&x,&y,&z);
		write(fd, &x, sizeof(x));
		write(fd, &y, sizeof(y));
		write(fd, &z, sizeof(z));
		close(fd);
	}
	return 0;
}
/*compile and run*/