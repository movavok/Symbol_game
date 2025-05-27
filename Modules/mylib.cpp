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

string choosePlayerColor(char handleColor){ // not using
    switch (handleColor){
    case '1': return "\033[91m"; break; //
    case '2': return "\033[92m"; break; //
    case '3': return "\033[93m"; break; //
    case '4': return "\033[94m"; break; //
    case '5': return "\033[95m"; break; //
    case '0': return "\033[90m"; break; //
    }
}

void showMap(char map[sizeWorldY][sizeWorldX], character pl, string playerColor){
    system("cls");
    string color, stop = "\033[0m";
    for (int row = 0; row < sizeWorldY; row++){
        for (int col = 0; col < sizeWorldX; col++){
            switch (map[row][col]){
            case '~':
            case '.': color = "\033[32m"; break; // green
            default:  color = "\033[35m";
            }

            if (pl.x == col && pl.y == row) cout << playerColor << '&' << stop;
            else cout << color << map[row][col] << stop;
        }
        cout << "\n";
    }
}

bool movePlayer(char map[sizeWorldY][sizeWorldX], char action, character* pl){
    int currentX = pl->x;
    int currentY = pl->y;
    switch (action){
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
    string pc = "\033[91m";
    while (true){
        char handle = tolower(getch());
        if (handle >= '0' && handle <= '5') pc = choosePlayerColor(handle); showMap(map, pl, pc);
        if (movePlayer(map, handle, &pl)){
            showMap(map, pl, pc);
            cout << "[" << pl.x << "/" << pl.y << "]";
        }
    }
}
