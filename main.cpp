#include <iostream>
using namespace std;

#include "SingleAgentStateTester.h"

int main() {
    Tester *t = new SingleAgentStateTester();
    t->test();
    return 0;
}
