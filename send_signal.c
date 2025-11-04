/**
* @file send_signal.c
* @author Nathan Eppler <epplern@msoe.edu>
* @date 3 November 2025
* @brief
*/

/**
 * File: send_signal.c
 * Modified by: Nathan Eppler <epplern@msoe.edu>
 * 
 * Brief summary of program:
 *
 * To Send SIGUSR1: -kill SIGUSR1 <pid>
 */

 #include <signal.h>
 #include <stdio.h>

 void usr1_handler(int pid) {
    printf("Sender PID: %d", pid);
 }

 int main(void) {
    struct sigaction sa = {0}; //set all struct fields to zero
    sa.sa_handler = &usr1_handler;
    sigaction(SIGUSR1, &sa, NULL);


    while (true) {
        sleep(1);
    }

    return 0;
 }
