#include "tools.h"
#include "player.h"
#include "dungeon.h"

int main(int argc, char** argv)
{
    title("Welcome to this text based adventure game");

    initPlayerName();

    initPlayerStats();

    choosePath();

    encounterMonster();

    return 0;
}