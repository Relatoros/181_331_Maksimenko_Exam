#include <iostream>
#include "Matrix.h"





int main() {
    Matrix a(2), b(2);

    int** test1 = new int* [2];
    test1[0] = new int[2]{ 1,2 };
    test1[1] = new int[2]{ 3,4 };

    a.setData((int**)test1);
    b.fillRand();

    Matrix c(2), d(2);
    c = a + b;
    d = a - b;

    a.show();
    b.show();
    c.show();
    d.show();
}