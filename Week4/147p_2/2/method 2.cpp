#include <iostream>
using namespace std;

int reverse(int n);

int main() {
    int num = 12345;
    cout << reverse(num) << endl;
    return 0;
}

int reverse(int n) {
    int result = 0;
    while (n > 0) {
        result = result * 10 + (n % 10);
        n /= 10;
    }
    return result;
}