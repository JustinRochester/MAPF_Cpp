//
// Created by Administrator on 2023/3/7.
//

#ifndef MAPF_CPP_SINGLEAGENTSTATETESTER_H
#define MAPF_CPP_SINGLEAGENTSTATETESTER_H

#include "Tester.h"
#include "SingleAgentState.h"

class SingleAgentStateTester : public Tester {
public:
    void run() override {
        SingleAgentState s(Position(2, 4), 2);
        SingleAgentState t;
        cout<<s.get_position()<<" "<<s.get_time()<<endl;
        cout<<t<<endl;
        cin>>t;

        cout<<(s==t)<<" "<<(s!=t)<<endl;
        cout << s.get_hash() << " " << t.get_hash() << endl;

        cout<<s.apply(t.get_position())<<endl;

        t.set_position(Position(2, 4));
        t.set_time(2);
        cout<<(s==t)<<" "<<(s!=t)<<endl;
        cout<<SingleAgentState::SingleStateAgentHasher()(s)<<" "<<SingleAgentState::SingleStateAgentHasher()(t)<<endl;
    }
};


#endif //MAPF_CPP_SINGLEAGENTSTATETESTER_H
