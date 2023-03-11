#include <iostream>
using namespace std;

#include "IDTester.h"

int main() {
    Tester *t = new IDTester();
    t->test();
    return 0;
}
