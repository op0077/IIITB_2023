#include <stdio.h>
#include <unistd.h>

int main() {
    const char* targetPath = "/media/dart/OS/Users/opdar/BVM/Mtech admission/iiit banglor/1st sem/Linux_shell/Handson_1/dest.txt";
    const char* symlinkPath = "op1";

    // Create a symbolic link
    if (symlink(targetPath, symlinkPath) == -1) {
        perror("symlink");
        return 1;
    }

    printf("Symbolic link created.\n");
    return 0;
}
