//
// Created by Administrator on 2023/3/7.
//

#ifndef MAPF_CPP_MAPREADERTESTER_H
#define MAPF_CPP_MAPREADERTESTER_H

#include "Tester.h"
#include "MapReader.h"

class MapReaderTester : public Tester {
public:
    void run() override {
        MapReader r;
        r.load_scenario("room-32-32-4", "random", 25, 10);
        cout<<r.get_agent_number()<<endl;

        for(int i=0; i<r.get_agent_number(); ++i)
            cout<<i+1<<":\t"<<r.get_start_positions()[i]<<"->"<<r.get_goal_positions()[i]<<endl;
        cout<<endl;

        const Map &m = r.get_maps();
        cout<<m.get_height()<<" "<<m.get_width()<<endl;
        for(int i=0; i<m.get_height(); ++i)
            for(int j=0; j<m.get_width(); ++j)
                cout<<m[i][j]<<" \n"[j==m.get_width()-1];
    }
};


#endif //MAPF_CPP_MAPREADERTESTER_H
