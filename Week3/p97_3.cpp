#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    int n;
    double pi_sum = 0.0;
    cin >> n;

    for (int i = 0; i <= n; i++) {
        if (i % 2 == 0) {
            pi_sum += 1.0 / (2 * i + 1);
        } else {
            pi_sum -= 1.0 / (2 * i + 1);
        }
    }

    cout << fixed << setprecision(10) << 4 * pi_sum << endl;
    return 0;
}