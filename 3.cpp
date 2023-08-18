#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
int main()
{
    int x = creat("new_file",O_CREAT);
    if(x<0)
    {
        perror("File not created");
        return 1;
    
    }
    close(x);
    return 0;

}