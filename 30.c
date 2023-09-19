/*
============================================================================
Name : 30.c
Author : Harshilkumar Buha
Description : Write a program to run a script at a specific time using a Daemon process
Date: 9th sep, 2023.
============================================================================
*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <time.h>
int main(){
	pid_t pid;
	time_t ct;
	struct tm tm;
	
	tm.tm_hour = 23;
	tm.tm_min = 22;
	tm.tm_sec = 0;
	
	while(1){
		time(&ct); 
		struct tm* c_tm = localtime(&ct);
		if(c_tm->tm_hour == tm.tm_hour && c_tm->tm_min == tm.tm_min)
		{
			execlp("ls","ls","-l",NULL); 
			break;
		} 
	}
}
/*compile*/
/* give time according to the time 1 or 2 min in fuute then current time*/
/*run program in background and wait*/