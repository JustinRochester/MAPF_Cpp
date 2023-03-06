//
// Created by Administrator on 2023/3/6.
//

#ifndef MAPF_CPP_TESTER_H
#define MAPF_CPP_TESTER_H

#include <bits/stdc++.h>
using namespace std;

class Tester {
public:
    virtual void run() = 0;
    void test() {
        try {
            run();
        }
        catch(const char *msg) {
            cerr<<msg;
        }
    }
};


#endif //MAPF_CPP_TESTER_H
