#include "header.h"

int main()
{
    char map[sizeWorldY][sizeWorldX];

    character player;
    player.x = sizeWorldX / 2;
    player.y = sizeWorldY / 2;

    generateMap(map);
    showMap(map, player);

    mainLoop(map, player);

    return 0;
}
