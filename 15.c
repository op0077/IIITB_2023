/*
============================================================================
Name : 15.c
Author : Harshilkumar Buha
Description : Write a program to display the environmental variable of the user (use environ).
Date: 29th aug, 2023.
============================================================================
*/
#include <stdio.h>
int main() {
    extern char **environ;
    for (int i = 0; environ[i] != NULL; ++i) 
        printf("%s\n",environ[i]);
    return 0;
}
/*compile and run*/