//
// Created by Administrator on 2023/3/7.
//

#ifndef MAPF_CPP_HEURISTICMAPTESTER_H
#define MAPF_CPP_HEURISTICMAPTESTER_H

#include "HeuristicMap.h"
#include "MapReader.h"
#include "Tester.h"

class HeuristicMapTester : public Tester {
public:
    void run() override {
        MapReader r;
        r.load_scenario("room-32-32-4", "random", 25, 1);
        Map m = r.get_maps();

        cout<<r.get_start_positions()[0]<<"->"<<r.get_goal_positions()[0]<<endl;

        for(int i=0; i<m.get_height(); ++i)
            for(int j=0; j<m.get_width(); ++j)
                if(i==r.get_goal_positions()[0].gety() && j==r.get_goal_positions()[0].getx())
                    cout<<"*1"[m[i][j]]<<" \n"[j==m.get_width()-1];
                else
                    cout<<"_1"[m[i][j]]<<" \n"[j==m.get_width()-1];
        cout<<endl;

        vector<pair<Vector, HEURISTIC_TYPE> > allowed_operations;
        allowed_operations.emplace_back(Vector(0, 0), 1);
        allowed_operations.emplace_back(Vector(0, 1), 1);
        allowed_operations.emplace_back(Vector(0, -1), 1);
        allowed_operations.emplace_back(Vector(1, 0), 1);
        allowed_operations.emplace_back(Vector(-1, 0), 1);

        HeuristicMap hm;
        hm.calculate_heuristic(m, r.get_goal_positions()[0], allowed_operations);

        for(int i=0; i<m.get_height(); ++i)
            for(int j=0; j<m.get_width(); ++j)
                cout<<setw(3)<<hm[i][j]<<" \n"[j==m.get_width()-1];
    }
};


#endif //MAPF_CPP_HEURISTICMAPTESTER_H
