#ifndef PLAYERINFO_H
#define PLAYERINFO_H

#define STR_SIZE 20
#define PLAYER_STATS_COUNT 3

struct playerInfo
{
    char charname[STR_SIZE];
    int stats[PLAYER_STATS_COUNT];
};

enum { stre, agi, intel };

#endif // PLAYERINFO_H