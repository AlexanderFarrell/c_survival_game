#ifndef ENGINE_H_H
#define ENGINE_H_H

// Presents options to the user and gets their response
int get_option(char * prompt, char ** options, int option_count);

// Presents a yes or no question to the user. 
// Returns 1 for yes, 0 for no
int yes_or_no(char * prompt);

// Initializes random numbers with a time-based seed.
// This is important if you want different numbers each time
// you play the game.
void rand_init();

// Gets a random number between min and max, not inclusive.
// For example a min of 0 and max of 5 would give you a 
// number between 0 and 4
int rand_integer(int min, int max);

#endif