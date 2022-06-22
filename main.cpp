#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

char pos[3][3];

void right() {
    for (int i = 0; i < 5; ++i) {
        if (pos[i][0] == 'x') {
            pos[i][0] = 'o';
            pos[i + 1][0] = 'x';
            break;
        } else if (pos[i][1] == 'x') {
            pos[i][1] = 'o';
            pos[i + 1][1] = 'x';
            break;
        } else if (pos [i][2] == 'x') {
            pos[i][2] = 'o';
            pos[i + 1][2] = 'x';
            break;
        } else if (pos [i][3] == 'x') {
            pos[i][3] = 'o';
            pos[i + 1][3] = 'x';
            break;
        } else if (pos [i][4] == 'x') {
            pos[i][4] = 'o';
            pos[i + 1][4] = 'x';
            break;
        }
    }
}


void left() {
    for (int i = 0; i < 5; ++i) {
        if (pos[i][0] == 'x') {
            pos[i][0] = 'o';
            pos[i - 1][0] = 'x';
            break;
        } else if (pos[i][1] == 'x') {
            pos[i][1] = 'o';
            pos[i - 1][1] = 'x';
            break;
        } else if (pos [i][2] == 'x') {
            pos[i][2] = 'o';
            pos[i - 1][2] = 'x';
            break;
        } else if (pos [i][3] == 'x') {
            pos[i][3] = 'o';
            pos[i - 1][3] = 'x';
            break;
        } else if (pos [i][4] == 'x') {
            pos[i][4] = 'o';
            pos[i - 1][4] = 'x';
            break;
        }
    }

}

void up() {
    for (int i = 0; i < 5; ++i) {
        if (pos[0][i] == 'x') {
            pos[0][i] = 'o';
            pos[0][i - 1] = 'x';
            break;
        } else if (pos[1][i] == 'x') {
            pos[1][i] = 'o';
            pos[1][i - 1] = 'x';
            break;
        } else if (pos [2][i] == 'x') {
            pos[2][i] = 'o';
            pos[2][i - 1] = 'x';
            break;
        } else if (pos [3][i] == 'x') {
            pos[3][i] = 'o';
            pos[3][i - 1] = 'x';
            break;
        } else if (pos [4][i] == 'x') {
            pos[4][i] = 'o';
            pos[4][i - 1] = 'x';
            break;
        }
    }

}

void down() {
    for (int i = 0; i < 5; ++i) {
        if (pos[0][i] == 'x') {
            pos[0][i] = 'o';
            pos[0][i + 1] = 'x';
            break;
        } else if (pos[1][i] == 'x') {
            pos[1][i] = 'o';
            pos[1][i + 1] = 'x';
            break;
        } else if (pos [2][i] == 'x') {
            pos[2][i] = 'o';
            pos[2][i + 1] = 'x';
            break;
        } else if (pos [3][i] == 'x') {
            pos[3][i] = 'o';
            pos[3][i + 1] = 'x';
            break;
        } else if (pos [4][i] == 'x') {
            pos[4][i] = 'o';
            pos[4][i + 1] = 'x';
            break;
        }
    }

}

void shoot(int bullet_y) {
    cout << "Bullet y: " << bullet_y << "\n";
}

void display() {
    cout << pos[0][0] << " " << pos[1][0] << " " << pos[2][0] << " " << pos[3][0] << " " << pos[4][0];

    cout << "\n";

    cout << pos[0][1] << " " << pos[1][1] << " " << pos[2][1] << " " << pos[3][1] << " " << pos[4][1];

    cout << "\n";

    cout << pos[0][2] << " " << pos[1][2] << " " << pos[2][2] << " " << pos[3][2] << " " << pos[4][2];

    cout << "\n";

    cout << pos[0][3] << " " << pos[1][3] << " " << pos[2][3] << " " << pos[3][3] << " " << pos[4][3];

    cout << "\n";

    cout << pos[0][4] << " " << pos[1][4] << " " << pos[2][4] << " " << pos[3][4] << " " << pos[4][4];

    cout << "\n";
}

int main() {
    bool game_act = true;

    char move;


    for (int i = 0; i <= 4; ++i) {
        for (int j = 0; j <= 4; ++j) {
            pos[i][j] = 'o';
        }
    }

    pos[0][0] = 'x';

    while (game_act) {
        display();

        cin >> move;

        if (move == 'd') {
            right();
        } else if (move == 'a') {
            left();
        } else if (move == 'w') {
            up();
        } else if (move == 's') {
            down();
        }

//        srand(static_cast <unsigned int> (time(0)));
        shoot(rand()%(4-0 + 1) + 0);

}

    return 0;
}
