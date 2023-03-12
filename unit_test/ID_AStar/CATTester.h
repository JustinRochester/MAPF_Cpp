//
// Created by Administrator on 2023/3/12.
//

#ifndef MAPF_CPP_CATTESTER_H
#define MAPF_CPP_CATTESTER_H

#include "Tester.h"
#include "CAT.h"

class CATTester : public Tester {
public:
    void run() override {
        CAT table;
        cout<<sizeof(table)<<endl;

        table.add(Position(0, 0), 0);
        cout<<sizeof(table)<<endl;

        table.add(Position(0, 1), 1);
        cout<<sizeof(table)<<endl;

        table.erase(Position(0, 2), 2);
        cout<<sizeof(table)<<endl;

        table.erase(Position(0, 1), 1);
        cout<<sizeof(table)<<endl;

        cout<<table.conflict_number(Position(0, 0), 0)<<endl;
        cout<<table.conflict_number(Position(0, 1), 1)<<endl;
    }
};


#endif //MAPF_CPP_CATTESTER_H
