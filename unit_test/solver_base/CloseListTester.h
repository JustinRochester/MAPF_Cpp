//
// Created by Administrator on 2023/3/7.
//

#ifndef MAPF_CPP_CLOSELISTTESTER_H
#define MAPF_CPP_CLOSELISTTESTER_H

#include "Tester.h"
#include "CloseList.h"
#include "SingleAgentState.h"

class CloseListTester : public Tester {
public:
    void run() override {
        CloseList close;

        mt19937 rnd(time(0));
        int q = 100;

        for(int i=1; i<=q; ++i) {
            int op = rnd()&1;
            int x = rnd()&7, y=rnd()&7;
            SingleAgentState *s = new SingleAgentState(Position(x, y), 0);
            if(op==0) {
                cout<<"add "<<*s<<endl;
                close.add(s);
            }
            else {
                cout<<"query "<<*s<<endl;
                cout<<">>>"<<close.exists(s)<<endl;
            }
            cout<<"==================="<<endl;
        }
    }
};


#endif //MAPF_CPP_CLOSELISTTESTER_H
