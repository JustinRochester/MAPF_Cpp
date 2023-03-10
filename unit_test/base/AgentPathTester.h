//
// Created by Administrator on 2023/3/10.
//

#ifndef MAPF_CPP_AGENTPATHTESTER_H
#define MAPF_CPP_AGENTPATHTESTER_H

#include "Tester.h"
#include "AgentPath.h"

class AgentPathTester : public Tester {
public:
    void run() override {
        AgentPath a;
        a.get_position_list() = vector<Position>({
                                                         Position(2, 2),
                                                         Position(3, 5)
                                                 });
        for(int i=0; i<10; ++i)
            cout<<i<<" "<<a[i]<<endl;
    }
};


#endif //MAPF_CPP_AGENTPATHTESTER_H
