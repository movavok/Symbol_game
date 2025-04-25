#include "header.h"

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

bool movePlayer(char map[sizeWorldY][sizeWorldX], char action, character* pl){
    int currentX = pl->x;
    int currentY = pl->y;
    switch(action) {
    case 'w': currentY--; break;
    case 's': currentY++; break;
    case 'a': currentX--; break;
    case 'd': currentX++; break;
    }
    if (isMovable(map, currentX, currentY)){
        map[pl->y][pl->x] = '.';
        pl->x = currentX;
        pl->y = currentY;
        return true;
    }
    else return false;
}

bool isMovable(char map[sizeWorldY][sizeWorldX], int x, int y) { return map[y][x] == '~' || map[y][x] == '.'; }

void mainLoop(char map[sizeWorldY][sizeWorldX], character pl){
    while (true){
        if (movePlayer(map, tolower(getch()), &pl)) showMap(map, pl);
        cout << pl.x << pl.y;
    }
}
