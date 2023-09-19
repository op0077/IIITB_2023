/*
============================================================================
Name : 18_2.c
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
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

int main()
{
	
	int fd = open("18_record.txt", O_RDWR);
	
	int a,b,c;
	read(fd, &a, sizeof(a));
	read(fd, &b, sizeof(b));
	read(fd, &c, sizeof(c));
	printf("Current values of records:\n1)a: %d \n2)b : %d\n3)c: %d\n",a,b,c);

	printf("choose Bus Number(1 or 2 or 3): \n");
	int record, start;
	scanf("%d",&record);
	fflush(stdin); // to clear inputbuffer
	fflush(stdout); // to clear outbuffer
	if(record == 1 || record == 2 || record == 3){
		start = (record-1)*sizeof(record);
	}
	else
	{
		printf("wrong input\n");
		return 0;
	}
	
	lseek(fd, start, SEEK_SET);
	struct flock lock;
	lock.l_type = F_WRLCK;
	lock.l_whence = SEEK_SET;
	lock.l_start = start;
	lock.l_len = sizeof(int);
	lock.l_pid = getpid();
	
	printf("Before entering the critical section.\n");
	int lock1 = fcntl(fd, F_SETLKW, &lock);
	if(lock1 == -1)
	{
		printf("lock is not auired\n");
	}
	else
	{
		printf("Got the lock, we are in critical section.\n");
	}
	
	int value;
	int rd = read(fd, &value, sizeof(value));
	if(rd != -1)
	{
		printf("New value to be updated for record %d is : %d\n",record,++value);		
	}
	else
	{
		printf("Not able to read from the file\n");
	}
	lseek(fd, start, SEEK_SET);
	rd = write(fd, &value, sizeof(value));
	if(rd == -1)
	{
		printf("Not able to update the record-value in file.\n");
	}
	else
	{
		printf("Record-value is now updated in the file.\n");
	}
	
	printf("Enter any character to unlock the record\n");
	getchar();
	getchar();
	lock.l_type = F_UNLCK;
	lock1 = fcntl(fd, F_SETLKW, &lock);
	if(lock1 == -1)
	{
		printf("Unable to release the lock over the record.\n");
	}
	else
	{
		printf("Exited critical section.\n");
	}
	close(fd);
	return 0;
}
/*compile and run in 2 terminal*/