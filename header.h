#ifndef HEADER_H
#define HEADER_H

#include <iostream>
#include <conio.h>

using namespace std;

const int sizeWorldX = 55;
const int sizeWorldY = 25;

struct character{
    int x;
    int y;
};

void generateMap(char map[sizeWorldY][sizeWorldX]);
void showMap(char map[sizeWorldY][sizeWorldX], character);
bool movePlayer(char map[sizeWorldY][sizeWorldX], char, character*);
void mainLoop(char map[sizeWorldY][sizeWorldX], character);
bool isMovable(char map[sizeWorldY][sizeWorldX], int x, int y);

#endif // HEADER_H
