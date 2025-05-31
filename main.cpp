#include "header.h"

void advMode(){
    char map[sizeWorldY][sizeWorldX];

    character player;
    string playerColor = "\033[91m";
    player.x = sizeWorldX / 2;
    player.y = sizeWorldY / 2;

    generateMap(map, '~');
    showMap(map, player, playerColor);

    advLoop(map, player, playerColor, '.');
}

void paintMode(){
    char map[sizeWorldY][sizeWorldX];

    character player;
    string playerColor = "\033[97m";
    player.x = sizeWorldX / 2;
    player.y = sizeWorldY / 2;

    generateMap(map, ' ');
    showMap(map, player, playerColor);

    advLoop(map, player, playerColor, '`');
}

char startMenu(){
    char choice;
    char mych;
    cout << "Enter what mode of game do you want to play\n"
         << "A/a -> Adventure Mode\n"
         << "P/p -> Paint Mode\n"
         << ">>> ";
    while(true){
        cin >> choice;
        mych = tolower(choice);
        if (mych == 'a' || mych == 'p') return mych;
        else {
            cout << "Enter 'a' or 'p' to choose the mode: ";
            continue;
        }
    }
}

int main()
{
    switch (startMenu()){
    case 'a': advMode();
    case 'p': paintMode();
    }

    return 0;
}
