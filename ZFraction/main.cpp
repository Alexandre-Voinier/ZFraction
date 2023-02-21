#include <iostream>

#include "ZFraction.h"

using namespace std;

int main()
{
    cout << "Presentation of ZFraction" << endl;

    ZFraction lv_a(4, 5);
    ZFraction lv_b(2);
    ZFraction lv_c, lv_d;

    lv_c = lv_a + lv_b;

    lv_d = lv_a * lv_b;

    cout << lv_a << " + " << lv_b << " = " << lv_c << endl;
    cout << lv_a << " * " << lv_b << " = " << lv_d << endl;

    if (lv_a > lv_b)
        cout << "A est plus grand que B" << endl;
    else if (lv_a == lv_b)
        cout << "A est egal a B" << endl;
    else
        cout << "A est plus petit que B";

    return 0;
}