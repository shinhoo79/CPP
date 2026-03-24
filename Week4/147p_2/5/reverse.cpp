#include "reverse.h"

int reverse(int n) {
    int result = 0;
    while (n > 0) {
        result = result * 10 + (n % 10);
        n /= 10;
    }
    return result;
}