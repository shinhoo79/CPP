#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

void randomMap(int map[5][5]);
void printMap(int map[5][5]);
void checkMap(int map[5][5]);

int main() {
    int map[5][5];

    srand(time(0));

    randomMap(map);
    printMap(map);
    checkMap(map);

    return 0;
}

void randomMap(int map[5][5]) {
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            map[i][j] = rand() % 2;
        }
    }
}

void printMap(int map[5][5]) {
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            cout << map[i][j] << " ";
        }
        cout << endl;
    }
}

void checkMap(int map[5][5]) {
    for (int i = 0; i < 5; i++) {
        bool rowSame = true;
        bool colSame = true;

        for (int j = 1; j < 5; j++) {
            if (map[i][j] != map[i][0]) rowSame = false;
            if (map[j][i] != map[0][i]) colSame = false;
        }

        if (rowSame) cout << "가로 줄 " << i << " 동일" << endl;
        if (colSame) cout << "세로 줄 " << i << " 동일" << endl;
    }

    bool diag1 = true;
    bool diag2 = true;

    for (int i = 1; i < 5; i++) {
        if (map[i][i] != map[0][0]) diag1 = false;
        if (map[i][4 - i] != map[0][4]) diag2 = false;
    }

    if (diag1) cout << "대각선 \\ 동일" << endl;
    if (diag2) cout << "대각선 / 동일" << endl;
}