#include <iostream>
#include <conio.h>

using namespace std;

const int map_size = 237;
const int map_max_y = 50;

int pos[map_size][map_size];

int x = 0, y = 0;

#define RESET   "\033[0m"
#define RED     "\033[1;31m"
#define BLACK   "\033[1m\033[30m"
#define BLUE    "\033[34m"

void move(char direction) {
    for (int i = 0; i < map_size; i++) {
        for (int j = 0; j < map_size; j++) {
            if (pos[j][i] == 1) {
                y = i;
                x = j;
            }
        }
    }

    if (direction == 'd') {
        if (y == map_max_y - 1) {
            cout << "Can't go down" << endl;
        } else {
            pos[x][y] = 0;
            pos[x][y + 1] = 1;
        }
    } else if (direction == 'u') {
        if (y == 0) {
            cout << "Can't go up" << endl;
        } else {
            pos[x][y] = 0;
            pos[x][y - 1] = 1;
        }
    } else if (direction == 'l') {
        if (x == 0) {
            cout << "Can't go left" << endl;
        } else {
            pos[x][y] = 0;
            pos[x - 1][y] = 1;
        }
    } else if (direction == 'r') {
        if (x == map_size - 1) {
            cout << "Can't go right" << endl;
        } else {
            pos[x][y] = 0;
            pos[x + 1][y] = 1;
        }
    }
}

void print() {
    int i, j = 0;

    for (i = 0; i < map_max_y; i++) {
        for (j = 0; j < map_size; j++) {
            if (pos[j][i] == 1) {
                cout << RED << "X" << RESET;
            } else {
                cout << "x";
            }
        }
        cout << endl;
    }
    cout << "\n\n\n";
}

void clear() {
    cout << string(100, '\n');
}

void game_control() {
    while (1) {
        print();
        char input;
        input = _getche();

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

int main() {
    pos[map_size / 2][map_max_y / 2] = 1;

    game_control();
}

