#include <iostream>
#include <string>
using namespace std;

int main() {
    int n;
    cin >> n;

    int units[] = {10000, 1000, 100, 10, 1};
    string names[] = {"만", "천", "백", "십", ""};

    for (int i = 0; i < 5; i++) {
        int digit = (n / units[i]) % 10;
        if (digit > 0) {
            if (digit == 1 && units[i] >= 10) {
                cout << names[i] << " ";
            } else {
                cout << digit << names[i] << " ";
            }
        }
    }
    cout << endl;
    return 0;
}