#include <iostream>
using namespace std;

#include "CloseListTester.h"

int main() {
    Tester *t = new CloseListTester();
    t->test();
    return 0;
}
