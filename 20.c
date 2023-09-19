/*
============================================================================
Name : 20.c
Author : Harshilkumar Buha
Description : Find out the priority of your running program. Modify the priority with nice command.
Date: 2nd sep, 2023.
============================================================================
*/
#include<fcntl.h>
#include<stdio.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<unistd.h>
#include<sys/resource.h>
int main()
{
    int p = getpriority(PRIO_PROCESS,0);
    printf("%d\n",p);
    int w = getpid();
    printf("current process id : %d\n",w);
    int ans;
    while(1)
    {
        printf("enter choice \n");
        printf("1) check priority\n");
        printf("2) exit \n");
        scanf("%d",&ans);
        if(ans==2)
            break;
        p = getpriority(PRIO_PROCESS,0);
        printf("current priority :%d\n",p);
        printf("eneter new priority\n");
        int k;
        scanf("%d",&k);
        nice(k);
        p = getpriority(PRIO_PROCESS,0);
        printf("new priority :%d\n",p);
    }
    return 0;
    // run "sudo renice -n <priority> -p <pid>"  
}
