#include <iostream>
using namespace std;

int reverse(int n) {
    int result = 0;
    while (n > 0) {
        result = result * 10 + (n % 10);
        n /= 10;
    }
    return result;
}

int main() {
    cout << reverse(12345) << endl;
    return 0;
}