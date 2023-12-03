#include <stdio.h>
#include <stdlib.h> 
#include <sys/wait.h>
#include <unistd.h>

void child_funk(){
    execl("./app_test_2", "main2", NULL);
    exit(0);
}

int main(){
    printf("forking\n");
    printf("parent process (%d) waiting for the child...\n", getpid());
    pid_t pid = fork();
    if (pid == 0){
        child_funk();
    } else {
        waitpid(pid, NULL, 0);
        printf("Child finished\n"); //ande geia sou paidi mou
    }
    printf("Parent finished\n"); //ande geia sou kai se esena
    return 0;
}