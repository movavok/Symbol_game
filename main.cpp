#include <iostream>
#include <conio.h>

using namespace std;

const int sizeWorldX = 55;
const int sizeWorldY = 25;

struct character{
    int x;
    int y;
};

void generateMap(char map[sizeWorldY][sizeWorldX]){
    for (int row = 0; row < sizeWorldY; row++)
        for (int col = 0; col < sizeWorldX; col++){
            char symbol = '~';
            if (col == 0 || col == sizeWorldX - 1) symbol = '|';
            else if (row == 0 || row == sizeWorldY - 1) symbol = '-';
            if ((row == 0 && col == 0) ||
                (row == 0 && col == sizeWorldX - 1) ||
                (col == 0 && row == sizeWorldY - 1) ||
                (col == sizeWorldX - 1 && row == sizeWorldY - 1))
                symbol = '+';

            map[row][col] = symbol;
        }
}

void showMap(char map[sizeWorldY][sizeWorldX], character pl){
    system("cls");
    for (int row = 0; row < sizeWorldY; row++){
        for (int col = 0; col < sizeWorldX; col++){
            if (pl.x == col && pl.y == row) cout << '&';
            else cout << map[row][col];
        }
        cout << "\n";
    }
}

void movePlayer(char action, character* pl){
    switch(action) {
    case 'w': pl->y--; break;
    case 's': pl->y++; break;
    case 'a': pl->x--; break;
    case 'd': pl->x++; break;
    }
}

void mainLoop(char map[sizeWorldY][sizeWorldX], character pl){
    movePlayer(getch(), &pl);
    showMap(map, pl);
    mainLoop(map, pl);
}

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
