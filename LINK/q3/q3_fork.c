/* ===================================================================
 * Q3: fork, execve, wait, getpid, exit  (MAIN program)
 * -------------------------------------------------------------------
 * HOW TO RUN  (copy-paste each line into the terminal):
 *
 *     gcc -o binsearch q3_binsearch.c   # compile this FIRST, exact name 'binsearch'
 *     gcc q3_fork.c
 *     ./a.out
 *     # then type the numbers it asks for
 *
 * IMPORTANT: the child runs ./binsearch, so the search program
 * MUST be compiled with the name binsearch (the -o binsearch above).
 * ===================================================================
 */

#include<stdio.h>
#include<string.h>
#include<sys/types.h>
#include<stdlib.h>
#include<unistd.h>
#include<wait.h>

int main(int argc, char *argv[]) {
    printf("Main Function: \n");
    int retval = 1;
    pid_t pid = fork();

    if (pid < 0)
        printf("Error in fork operation\n");

    if (pid == 0) {                                  /* child */
        printf("PID for Child process: %d \nPID of its parent process: %d\n",
               getpid(), getppid());
        execl("./binsearch", "binsearch", NULL);
    } else {                                         /* parent */
        printf("PID of parent process: %d\n", getpid());
        wait(&retval);
        if (WIFEXITED(retval) == 1)
            printf("Child terminated normally\n");
        else {
            printf("Child terminated abnormally\n");
            exit(0);
        }
    }
    return 0;
}
