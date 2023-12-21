// Standard IO
// IO means in out. Allows you to *output* to console, and
// take user *input* from the console.
// Can do more than just console IO.
// Functions: printf(), scanf(), getline(), etc.
#include <stdio.h>

// Our engine code we wrote.
#include "engine.h"
#include "player.h"
#include "area.h"

Area areas[] = {
    // Name, Health_Delta, Hunger_Delta
    {"Forest 🌲", 0, 0},
    {"Desert 🌵", -5, -10},
    {"Jungle 🌴", -10, 0},
    {"Mountain ⛰", -15, -5},
    {"Ocean 🌊", 0, -10}
};
int areas_count = 5;

int main() {
    Player player;
    player_init(&player);

    int is_playing = 1;
    int day = 0;

    printf("== Welcome to Survival Game ==\n");

    while(is_playing) {
        if (!player_is_alive(&player)) {
            printf("You lasted %d days. Game Over.\n", day);
            break;
        }
        day++;
        printf("\nDay: %d \n", day);
        player_display(&player);

        Area* first_choice = &areas[rand_integer(0, areas_count)];
        Area* second_choice = &areas[rand_integer(0, areas_count)];

        char * options[] = {first_choice->name, second_choice->name, "Quit"};
        int choice = get_option("Where would you like to go?", options, 3);

        if (choice == 0) {
            stat_add(&player.health, first_choice->health_delta);
            stat_add(&player.hunger, first_choice->hunger_delta);
        } else if (choice == 1) {
            stat_add(&player.health, second_choice->health_delta);
            stat_add(&player.hunger, second_choice->hunger_delta);
        } else if (choice == 2) {
            printf("Quitting game\n");
            is_playing = 0;
        }
    }
}