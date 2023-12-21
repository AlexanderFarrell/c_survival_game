#include "engine.h"

// Standard IO
// IO means in out. Allows you to *output* to console, and
// take user *input* from the console.
// Can do more than just console IO.
// Functions: printf(), scanf(), getline(), etc.
#include <stdio.h> 

// Standard C library with tons of helpful functions.
// Bit of a mixed bag, but not too large
// Functions: srand(), malloc(), free()
#include <stdlib.h>

// Time library in C. Handles getting current time, and time 
// related functions.
// Functions: time()
#include <time.h>

int get_option(char * prompt, char ** options, int option_count) {
    // While loop lets us continually ask '
    // until the user types something valid
    while (1) {
        // Ask the question
        printf("%s \n", prompt);

        // Present all the options
        for (int i = 0; i < option_count; i++) {
            printf(" %d. %s \n", i+1, options[i]);
        }
        
        // Ask for a number
        printf("Type a number: ");
        int response;
        scanf("%d", &response);

        // Validate the number
        if (response < 1 || response > option_count) {
            // If they typed some invalid number, ask again.
            printf("Please type a number between 1 and %d\n", option_count);
        } else {
            // The user will type in 1 for the 1st number. But with arrays
            // the first item is 0. So we subtract 1 from what the user said.
            return response-1;
        }
    }
}

int yes_or_no(char * prompt) {
    // While loop lets us continually ask '
    // until the user types something
    while (1) {
        // Ask the question
        printf("%s (y or n): ", prompt);

        char response;
        scanf("%c", &response);

        // Validate the number
        if (response == 'y'  || response == 'Y') {
            return 1; // 1 = true
        } else if (response == 'n'  || response == 'N') {
            return 0; // 0 = false
        } else {
            // If they typed anything else, ask again.
            printf("Please type either y or n");
        }
    }
}

void rand_init() {
    // Seeds random numbers with the current time. 
    srand(time(NULL));
}

int rand_integer(int min, int max) {
    int difference = max - min;
    return (rand() % difference) + min;
}