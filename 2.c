/*
============================================================================
Name : 2.c
Author : Harshilkumar Buha
Description : Write a simple program to execute in an infinite loop at the background. Go to /proc directory and
identify all the process related information in the corresponding proc directory
Date: 27th aug, 2023.
============================================================================
*/
int main()
{
    while(1);
}
/* run file in background usin &(it will return a pid)
go to root directory using cd(it)
use cd/proc/<pid>
kill -9 <pid> to kill the process*/
