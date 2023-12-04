#include <stdio.h> // printf
#include <unistd.h> // fork
#include <sys/wait.h> // waitpid
#include <time.h> // clock_gettime
#include <sys/resource.h> // getpriority
#include <sched.h> // sched_getscheduler 

int getPolicy();
int getP();
void executeTask();

int main()
{
    printf("Making the kid...\n");
    pid_t pid = fork(); // dhmiourgia paidiou
    struct timespec start, end; // Struct pou exei to start kai to end tou xronou se timespec (nanosec) kai se sec 
    if (pid == 0){
        clock_gettime(CLOCK_MONOTONIC, &start); // edw ksekinaei o xronos (bgazei error alla douleuei)
        executeTask();
        clock_gettime(CLOCK_MONOTONIC, &end); // edw stamataei o xronos
        printf("I am the pid = %d, my nice value is : %d\n",getpid(),getP());
        printf("and my policy is : %d\n",getPolicy()); 
        printf("Time taken by pid %d : %ld\n", getpid(), end.tv_nsec - start.tv_nsec); // edw bgazei to xrono
        printf("kai se sec : %ld\n", end.tv_sec - start.tv_sec); // edw bgazei to xrono se sec
    } else {
        waitpid(pid, NULL, 0);
        clock_gettime(CLOCK_MONOTONIC, &start); // edw ksekinaei o xronos (bgazei error alla douleuei)
        executeTask();
        clock_gettime(CLOCK_MONOTONIC, &end); // edw stamataei o xronos
        printf("I am the pid = %d, my nice value is : %d\n",getpid(),getP());
        printf("and my policy is : %d\n",getPolicy());
        printf("Time taken by pid %d : %ld\n", getpid(), end.tv_nsec - start.tv_nsec); // edw bgazei to xrono
        printf("kai se sec : %ld\n", end.tv_sec - start.tv_sec); // edw bgazei to xrono se sec
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

