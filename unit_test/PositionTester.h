//
// Created by Administrator on 2023/3/7.
//

#ifndef MAPF_CPP_POSITIONTESTER_H
#define MAPF_CPP_POSITIONTESTER_H

#include "Position.h"
#include "Tester.h"

class PositionTester : public Tester {
public:
    void run() override {
        Position p(5, 6);
        cout<<p.getx()<<" "<<p.gety()<<endl;
        cout<<Position::PositionHasher()(p)<<endl;
        p.sety(7); p.setx(3);
        cout<<p<<endl;
        cout<<Position::PositionHasher()(p)<<endl;

        Position q;
        cin>>q;
        cout<<Position::PositionHasher()(q)<<endl;
        cout<<(p+q)<<" "<<(p-q)<<endl;
        cout<<Position::PositionHasher()(p+q)<<" "<<Position::PositionHasher()(p-q)<<endl;
    }
};


#endif //MAPF_CPP_POSITIONTESTER_H
