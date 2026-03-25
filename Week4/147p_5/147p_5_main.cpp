#include <iostream>
#include "147p_5.h"
#include <cstdlib>
#include <ctime>
using namespace std;

int main()
{
    int nTurn, nBullets, nSlot;

    srand(time(NULL));

    cout << "사람 수: ";
    cin >> nTurn;

    cout << "총 슬롯 수: ";
    cin >> nSlot;

    cout << "총알 개수: ";
    cin >> nBullets;

    cin.ignore();

    playRussianRoulette(nTurn, nBullets, nSlot);

    return 0;
}