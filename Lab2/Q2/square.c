#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
int main(int argc, char *argv[])
{
    if (argc<2){
        exit(0);
    }
    if (argc == 2)
    {
              
        int number = atoi(argv[1]);
        int value = number*number;
        printf("Square: Current process id: %d, Current result: %d\n", getpid(), value);
        return 0;
    }
    else {  
            
        int number = atoi(argv[argc-1]);
        printf("Square: Current process id: %d, Current result: %d\n", getpid(), number*number);
        sprintf(argv[argc - 1], "%d", number*number);
        execvp(argv[1], argv + 1);
    }
}
