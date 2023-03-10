//
// Created by Administrator on 2023/3/6.
//

#ifndef MAPF_CPP_COMMONTESTER_H
#define MAPF_CPP_COMMONTESTER_H

#include "Tester.h"
#include "common.h"

class commonTester : public Tester {
public:
    void run() override {
        HEURISTIC_TYPE a = eps/10;
        HEURISTIC_TYPE b = -a;
        HEURISTIC_TYPE c = eps*10;
        HEURISTIC_TYPE d = -c;
        cout<<sgn(a)<<" "<<sgn(b)<<" "<<sgn(c)<<" "<<sgn(d)<<endl;
    }
};


#endif //MAPF_CPP_COMMONTESTER_H
