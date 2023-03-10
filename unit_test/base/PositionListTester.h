//
// Created by Administrator on 2023/3/8.
//

#ifndef MAPF_CPP_POSITIONLISTTESTER_H
#define MAPF_CPP_POSITIONLISTTESTER_H

#include "Tester.h"
#include "PositionList.h"

class PositionListTester : public Tester {
public:
    void display(const PositionList &pl) {
        cout<<pl.get_position_list().size()<<endl;
    }
    void run() override {
        PositionList pl;
        pl.get_position_list() = vector<Position> ({
            Position(1, 2),
            Position(3, 4)
        });
        cout<<pl<<endl;
        cout<<pl.get_hash()<<endl;

        PositionList ql;
        cout<<ql<<endl;
        cout<<PositionList::PositionListHasher()(ql)<<endl;

        cin>>ql;
        cout<<(pl==ql)<<" "<<(pl!=ql)<<endl;
        cout<<pl[0]<<" "<<pl[1]<<endl;
        display(ql);
        cout<<ql[0]<<" "<<ql[1]<<endl;
    }
};


#endif //MAPF_CPP_POSITIONLISTTESTER_H
