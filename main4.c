#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <time.h>
#include <sys/resource.h>
#include <sched.h>

int getPolicy();
int getP();
void executeTask();

int main()
{
    printf("Making a kid\n");
    pid_t pid = fork();
    if (pid == fork()){
        executeTask();
        printf("I am the pid = %d, my nice value is : %d\n",getpid(),getP());
        printf("and my policy is : %d\n",getPolicy());
    } else {
        executeTask();
        printf("I am the pid = %d, my nice value is : %d\n",getpid(),getP());
        printf("and my policy is : %d\n",getPolicy());
    }
    return 0;
}

void executeTask()
{
    int oarithmos = 0;
    for (int i = 0; i < 1500000000; i++)
    {
        oarithmos += i;
    }
    
}

int getPolicy()
{
    int policy;
    policy = sched_getscheduler(0);
    return policy;
}

int getP(){
    int p;
    p = getpriority(PRIO_PROCESS, 0);
    return p;
}

