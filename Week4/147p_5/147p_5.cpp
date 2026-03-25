#include "147p_5.h"
#include <cstdlib>
#include <ctime>

void playRussianRoulette(int nTurns, int nBullets, int nSlot)
{
    int start = rand() % nTurns;
    int shotCount = 0;

    cout << "\n" << start + 1 << "번부터 시작!\n";

    while (shotCount < nBullets)
    {
        int pos = rand() % nSlot;

        cout << "[" << start + 1 << "번] 엔터 누르면 발사!";
        cin.ignore();

        if (pos < nBullets)
        {
            cout << " 💥 맞았다!\n";
            shotCount++;
        }
        else
        {
            cout << " 😅 살았다!\n";
        }

        start = (start + 1) % nTurns;
    }

    cout << "\n게임 끝!\n";
}