#include "header.h"

string openMenu(){
    string paintColor, white = "\033[37m", blue = "\033[34m", red = "\033[31m", green = "\033[32m", black = "\033[90m";
    while(true){
        system("cls");
        cout << "That is a menu of game with some instructions:\n"
             << "paint color[" << white << " 1"
             << blue << " 2"
             << red << " 3"
             << green << " 4"
             << black << " 0(eraser)\033[0m ]\n";
        cout << "'x' - to save a color";
        white = "\033[37m"; blue = "\033[34m"; red = "\033[31m"; green = "\033[32m"; black = "\033[90m";
        switch(getch()){
        case '1': white = "\033[97m"; paintColor = "\033[107m"; break;
        case '2': blue = "\033[94m"; paintColor = "\033[104m"; break;
        case '3': red = "\033[91m"; paintColor = "\033[101m"; break;
        case '4': green = "\033[92m"; paintColor = "\033[102m"; break;
        case '0': black = "\033[30m"; paintColor = "\033[40m"; break;
        case 'x': return paintColor;
        }
    }
}

void generateMap(char map[sizeWorldY][sizeWorldX], char back){
    for (int row = 0; row < sizeWorldY; row++)
        for (int col = 0; col < sizeWorldX; col++){
            char symbol = back;
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

void showMap(char map[sizeWorldY][sizeWorldX], character pl, string playerColor, string paintColor){
    system("cls");
    string color, stop = "\033[0m";
    for (int row = 0; row < sizeWorldY; row++){
        for (int col = 0; col < sizeWorldX; col++){
            switch (map[row][col]){
            case '~':
            case '.': color = "\033[32m"; break; // green
            case '`': color = paintColor; break;
            default:  color = "\033[35m";
            }

            if (pl.x == col && pl.y == row) cout << playerColor << '&' << stop;
            else cout << color << map[row][col] << stop;
        }
        cout << "\n";
    }
}

bool isMovable(char map[sizeWorldY][sizeWorldX], int x, int y) { return map[y][x] == '~' || map[y][x] == '.' || map[y][x] == ' ' || map[y][x] == '`'; }

bool movePlayer(char map[sizeWorldY][sizeWorldX], char action, character* pl, char trail){
    int currentX = pl->x;
    int currentY = pl->y;
    switch (action){
    case 'w': currentY--; break;
    case 's': currentY++; break;
    case 'a': currentX--; break;
    case 'd': currentX++; break;
    case 'r': system("cls"); main();
    }
    if (isMovable(map, currentX, currentY)){
        map[pl->y][pl->x] = trail;
        pl->x = currentX;
        pl->y = currentY;
        return true;
    }
    else return false;
}

void advLoop(char map[sizeWorldY][sizeWorldX], character pl, string pc, char trail){
    string tc = "\033[107m";
    while (true){
        char handle = tolower(getch());
        if(trail == '`' && handle == 'm') tc = openMenu();
        if (movePlayer(map, handle, &pl, trail)){
            showMap(map, pl, pc, tc);
            cout << "[" << pl.x << "/" << pl.y << "]";
        }
    }
}
