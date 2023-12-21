#include "player.h"
#include <stdio.h>

void stat_init(Stat * stat, char * name, int max) {
    stat->name = name;
    stat->value = max;
    stat->max = max;
}

void stat_display(Stat * stat) {
    printf("%s: %d/%d \n", stat->name, stat->value, stat->max);
}

void stat_add(Stat* stat, int amount) {
    stat->value += amount;
    if (stat->value < 0) {
        stat->value = 0;
    } else if (stat->value > stat->max) {
        stat->value = stat->max;
    }
}

void player_init(Player * player) {
    printf("What is your name (20 characters max): ");
    fgets(player->name, 19, stdin);

    stat_init(&player->health, "Health", START_HEALTH);
    stat_init(&player->hunger, "Hunger", START_HUNGER);
}

void player_display(Player * player) {
    stat_display(&player->health);
    stat_display(&player->hunger);
}

int player_is_alive(Player * player) {
    if (player->health.value <= 0) {
        return 0;
    }

    if (player->hunger.value <= 0) {
        return 0;
    }

    return 1;
}