/**
 * @file signal_segfault.c
 * @brief Program that dereferences a null pointer causing a segmentation fault
 */

/**
 * Modified by: Nathan Eppler
 * 
 * Brief summary of modifications: Modified the program to print out
 * "Segmentation violation handled" when the program encounters a SIGSEGV signal.
 *
 * This causes the program to infinitely print the handling message as it returns
 * to the same point where the SIGSEGV signal was sent as the program continues
 * to perform segmentation violations.
 */


#include <stdio.h>
#include <signal.h>

void segv_handler() {
    printf("Segmentation violation handled\n");
}

int main (int argc, char* argv[]) {
    //set up SIGSEGV handler
    struct sigaction sa = {0}; //set all struct fields to zero
    sa.sa_handler = &segv_handler;
    sigaction(SIGSEGV, &sa, NULL); //NULL val says don't store prev handler assignment

    // Declare a null pointer
    int* i = NULL;

    // Dereference the null pointer
    printf("The value of i is: %d\n", *i);

    // Return to exit the program
    return 0;
}