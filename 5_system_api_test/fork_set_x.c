#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>

//父子进程改变同一个值，不会相互影响
int main(int argc, char *argv[])
{
    printf("Hello zhizhi\n");
    int mainX  = 22;

    int rc = fork();
    if (rc < 0) {
        fprintf(stderr, "fork failed\n");
        exit(1);
    } else if (rc == 0) {
        //mainX = mainX + 1;
        printf("child process, mainX = %d\n", mainX);   //23
    } else {
        mainX = mainX + 100;
        printf("now is main process, mainX = %d\n", mainX); //122
    }
    return 0;
}