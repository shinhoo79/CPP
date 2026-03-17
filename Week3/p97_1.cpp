#include <iostream>
using namespace std;

int main()
{
    for(int i = 1; i <= 5; ++i)
    {
        for(int j = 1; j <= i; ++j)
            cout << j;
        cout << "\n";
    }

    cout << "\n";

    for(int i = 1; i <= 5; i++)
    {
        for(int j = 5; j >= i; j--)
            cout << j << " ";
        cout << "\n";
    }

    cout << "\n";

    for(int i = 1; i <= 5; ++i)
    {
        for(int space = 1; space <= 5 - i; ++space)
            cout << "  ";

        for(int j = i; j >= 1; --j)
            cout << j << " ";

        cout << "\n";
    }

    cout << "\n";

    for(int i = 1; i <= 5; ++i)
    {
        for(int space = 1; space <= 5 - i; ++space)
            cout << " ";

        for(int j = i; j >= 1; --j)
            cout << j;

        for(int j = 2; j <= i; ++j)
            cout << j;

        cout << "\n";
    }

    return 0;
}