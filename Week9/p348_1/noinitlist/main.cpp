#include "MyTime.h"

int main() {
    MyTime t1, t2, t3;

    MyTime t5(1, 2, 3, 400);
    t5.print();

    t1.read();
    t2.read();

    t3 = t1.add(t2);

    t1.print();
    t2.print();
    t3.print();

    t3.reset();
    t3.print();

    MyTime t4;
    t4.convert(3723.567);
    t4.print();

    return 0;
}