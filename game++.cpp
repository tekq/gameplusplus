#include <iostream>
#include "conio.h"

using namespace std;

const int map_size = 50;
const int map_max_y = 10;

int map[map_size][map_size];

int x = 0, y = 0;

int npc_count = 0;

#define RESET   "\033[0m"
#define RED     "\033[1;31m"
#define BLACK   "\033[1m\033[30m"
#define BLUE    "\033[34m"

void create_npc(int x, int y, string npc_type) {
    map[x][y] = 2;
    npc_count++;
}

void create_player(int x,
                   int y) { // create the player character, if coords are null then create the player in the middle of the map
    if (x != 0 && y != 0) {
        map[x][y] = 1;
    } else {
        map[map_size / 2][map_max_y / 2] = 1;
    }
}

void move(char direction) {
    for (int i = 0; i < map_size; i++) {
        for (int j = 0; j < map_size; j++) {
            if (map[j][i] == 1) {
                y = i;
                x = j;
            }
        }
    }

    if (direction == 'd') {
        if (y == map_max_y - 1) {
            cout << "Can't go down" << endl;
        } else if (map[x][y + 1] == 2) {
            // npc
        } else {
            map[x][y] = 0;
            map[x][y + 1] = 1;
        }
    } else if (direction == 'u') {
        if (y == 0) {
            cout << "Can't go up" << endl;
        } else if (map[x][y - 1] == 2) {

        } else {
            map[x][y] = 0;
            map[x][y - 1] = 1;
        }
    } else if (direction == 'l') {
        if (x == 0) {
            cout << "Can't go left" << endl;
        } else if (map[x - 1][y] == 2) {
            // npc
        } else {
            map[x][y] = 0;
            map[x - 1][y] = 1;
        }
    } else if (direction == 'r') {
        if (x == map_size - 1) {
            cout << "Can't go right" << endl;
        } else if (map[x + 1][y] == 2) {
            // npc
        } else {
            map[x][y] = 0;
            map[x + 1][y] = 1;
        }
    }
}

void print() {
    int i, j = 0;

    for (i = 0; i < map_max_y; i++) {
        for (j = 0; j < map_size; j++) {
            if (map[j][i] == 1) {
                cout << RED << "O" << RESET;
            } else if (map[j][i] == 2) { // npc
                cout << BLUE << "O" << RESET;
            } else {
                cout << "x";
            }
        }
        cout << endl;
    }

    cout << "x: " << x << " y: " << y << endl;

    cout << "NPCs: " << npc_count << endl;
//    cout << "\n\n\n";
}

void clear() {
    cout << string(100, '\n');
}

void game_control() {
    while (1) {
        print();
        char input;
        input = getche();

        if (input == 'q') { // quit game (CTRL+C doesn't work)
            break;
        } else if (input == 'w') { // move up
            move('u');
            clear();
        } else if (input == 'a') { // move left
            move('l');
            clear();
        } else if (input == 'd') { // move right
            move('r');
            clear();
        } else if (input == 's') { // move down
            move('d');
            clear();
        } else if (input == 'i') {
            clear();
            cout << "feature not implemented yet :(" << endl;
            cout << endl;
        } else {
            clear();
            cout << "Invalid input" << endl;
            cout << endl;
        }
    }
}

/* int main() {
    create_player(0, 0); // create the player in the middle of the map

    create_npc(5, 5, "Trader");

    game_control();
} */
