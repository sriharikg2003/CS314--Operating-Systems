#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <sys/wait.h>
void recurse(char * word ,int index){
    if (index==strlen(word)){
        return ;
    }
    printf("%c %d\n", word[index], getpid() );
    sleep((rand()%4) + 1);
    pid_t pid = fork();
    if (pid>0){
        wait(NULL);
    }
    else if (pid==0){
        recurse(word,index+1);
    }
    else {
        return;
    }
}
int main()
{    char word[12] = "Hello World";
    recurse(word,0);
    return 0;
}
// 28 lines is required however unnecessary lines with brackets can be ignored.
