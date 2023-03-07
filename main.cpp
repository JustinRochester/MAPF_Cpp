#include <iostream>
using namespace std;

#include "MultiAgentStateTester.h"

int main() {
    Tester *t = new MultiAgentStateTester();
    t->test();
    return 0;
}
