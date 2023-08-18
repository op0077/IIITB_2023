#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
int main()
{
    int x = open("emp.txt",O_RDWR|O_EXCL);
    if(x<0)
    {
        perror("File not opened");
        return 0;
    }
    printf("done\n");
    close(x);
    return 1;

}