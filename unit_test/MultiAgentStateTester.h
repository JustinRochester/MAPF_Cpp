//
// Created by Administrator on 2023/3/7.
//

#ifndef MAPF_CPP_MULTIAGENTSTATETESTER_H
#define MAPF_CPP_MULTIAGENTSTATETESTER_H

#include "Tester.h"
#include "MultiAgentState.h"

class MultiAgentStateTester : public Tester {
public:
    void display(const MultiAgentState &m) {
        for(const auto &pos : m.get_position())
            cout<<pos<<" ";
        cout<<endl;
        cout<<m.get_time()<<endl;
        cout<<m[0]<<endl;
    }
    void run() override {
        MultiAgentState m;
        cout<<m<<endl;

        m.set_time(3);
        m.get_position() = vector<Position>{Position(2,4), Position(3, 6)};
        cout<<m<<endl;

        MultiAgentState n;
        cin>>n;
        cout<<(m==n)<<" "<<(m!=n)<<endl;
        cout<<m.get_hasher()(m)<<" "<<MultiAgentState::MultiAgentStateHasher()(n)<<endl;

        m.apply(vector<Vector>{Position(0, 0), Position(1, 2)});
        display(m);
        cout<<n[0]<<endl;
    }
};


#endif //MAPF_CPP_MULTIAGENTSTATETESTER_H
