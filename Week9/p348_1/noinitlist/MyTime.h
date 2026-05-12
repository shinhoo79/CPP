#ifndef MYTIME_H
#define MYTIME_H

#include <iostream>
#include <iomanip>
using namespace std;

class MyTime {
private:
    int hour;
    int min;
    int sec;
    int msec;

public:
    inline MyTime(int h = 0, int m = 0, int s = 0, int ms = 0) {
        hour = h;
        min = m;
        sec = s;
        msec = ms;
    }

    inline void convert(double duration) {
        int total_msec = (int)(duration * 1000);
        hour = total_msec / (1000 * 60 * 60);
        total_msec %= (1000 * 60 * 60);
        min = total_msec / (1000 * 60);
        total_msec %= (1000 * 60);
        sec = total_msec / 1000;
        msec = total_msec % 1000;
    }

    inline void print() {
        cout << setw(2) << setfill('0') << hour << ":"
             << setw(2) << setfill('0') << min << ":"
             << setw(2) << setfill('0') << sec << ":"
             << setw(3) << setfill('0') << msec << endl;
    }

    inline MyTime add(MyTime t) {
        MyTime result;
        int total1 = ((hour * 60 + min) * 60 + sec) * 1000 + msec;
        int total2 = ((t.hour * 60 + t.min) * 60 + t.sec) * 1000 + t.msec;
        int sum = total1 + total2;

        result.hour = sum / (1000 * 60 * 60);
        sum %= (1000 * 60 * 60);
        result.min = sum / (1000 * 60);
        sum %= (1000 * 60);
        result.sec = sum / 1000;
        result.msec = sum % 1000;

        return result;
    }

    inline void reset() {
        hour = min = sec = msec = 0;
    }

    void read();
};

#endif