#include <iostream>
#include <conio.h>

using namespace std;

const int map_x = 30;
const int map_y = 30;

int pos[map_x][map_y];

int x = 0, y = 0;

#define RESET   "\033[0m"
#define RED     "\033[1;31m"

void move(char direction) {
    for (int i = 0; i < map_x; i++) {
        for (int j = 0; j < map_y; j++) {
            if (pos[j][i] == 0) {
                x = j;
                y = i;
            }
        }
    }

    if (direction == 'd') {
        if (y == map_y - 1) {
            cout << "Can't go down" << endl;
        } else {
            pos[x][y] = 1;
            pos[x][y + 1] = 0;
        }
    } else if (direction == 'u') {
        if (y == 0) {
            cout << "Can't go up" << endl;
        } else {
            pos[x][y] = 1;
            pos[x][y - 1] = 0;
        }
    } else if (direction == 'l') {
        if (x == 0) {
            cout << "Can't go left" << endl;
        } else {
            pos[x][y] = 1;
            pos[x - 1][y] = 0;
        }
    } else if (direction == 'r') {
        if (x == map_x - 1) {
            cout << "Can't go right" << endl;
        } else {
            pos[x][y] = 1;
            pos[x + 1][y] = 0;
        }
    }
}

void print() {
    for (int i = 0; i < map_x; i++) {
        for (int j = 0; j < map_y; j++) {
            if (pos[j][i] == 0) {
                cout << RED << pos[j][i] << " " << RESET;
            } else {
                cout << pos[j][i] << " ";
            }
        }
        cout << endl;
    }
    cout << "\n\n\n\n\n";

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
    cout << "Some random game lmao" << endl;
    cout << " - The Epic Game -" << endl;
    cout << " - By: Some Random Person -" << endl;

    cout << endl;

    cout << "Press any key to start" << endl;

    _getche();

    for (int i = 0; i < map_x; i++) { // set the map to 1s(better readability)
        for (int j = 0; j < map_y; j++) {
            pos[i][j] = 1;
        }
    }

    pos[map_x / 2][map_y / 2] = 0;

    clear();


    game_control();
}

