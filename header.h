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

int main();
void generateMap(char map[sizeWorldY][sizeWorldX], char);
void showMap(char map[sizeWorldY][sizeWorldX], character, string, string paintColor = "\033[107m");
void advLoop(char map[sizeWorldY][sizeWorldX], character, string, char);

#endif // HEADER_H
