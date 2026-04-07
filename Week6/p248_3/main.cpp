#include <iostream>
using namespace std;

struct MyTime {
    int hour;
    int min;
    int sec;
};

MyTime addTime(MyTime t1, MyTime t2) {
    MyTime result;
    result.sec = t1.sec + t2.sec;
    result.min = t1.min + t2.min + result.sec / 60;
    result.sec %= 60;
    result.hour = t1.hour + t2.hour + result.min / 60;
    result.min %= 60;
    return result;
}

void addTime(MyTime t1, MyTime t2, MyTime& t3) {
    t3.sec = t1.sec + t2.sec;
    t3.min = t1.min + t2.min + t3.sec / 60;
    t3.sec %= 60;
    t3.hour = t1.hour + t2.hour + t3.min / 60;
    t3.min %= 60;
}

void addTime(MyTime t1, MyTime t2, MyTime* pt) {
    pt->sec = t1.sec + t2.sec;
    pt->min = t1.min + t2.min + pt->sec / 60;
    pt->sec %= 60;
    pt->hour = t1.hour + t2.hour + pt->min / 60;
    pt->min %= 60;
}

int main() {
    MyTime t1 = {1, 50, 40};
    MyTime t2 = {2, 20, 30};

    MyTime r1 = addTime(t1, t2);

    MyTime r2;
    addTime(t1, t2, r2);

    MyTime r3;
    addTime(t1, t2, &r3);

    cout << r1.hour << ":" << r1.min << ":" << r1.sec << endl;
    cout << r2.hour << ":" << r2.min << ":" << r2.sec << endl;
    cout << r3.hour << ":" << r3.min << ":" << r3.sec << endl;

    return 0;
}