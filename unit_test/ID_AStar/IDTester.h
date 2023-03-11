//
// Created by Administrator on 2023/3/10.
//

#ifndef MAPF_CPP_IDTESTER_H
#define MAPF_CPP_IDTESTER_H

#include "Tester.h"
#include "AStar.h"
#include "MapReader.h"
#include "ID.h"

class IDTester : public Tester {
public:
    void display_map(const Map &maps) {
        for(int i=0; i<maps.get_height(); ++i) {
            for (int j = 0; j < maps.get_width(); ++j)
                cout << "01"[maps[i][j]];
            cout << endl;
        }
    }
    void display_problem(const vector<Position>& start_positions, const vector<Position> &goal_positions) {
        int n = start_positions.size();
        for(int i=0; i<n; ++i)
            cout<<start_positions[i]<<"->"<<goal_positions[i]<<endl;
    }
    void run() override {
        Solver *solver = new ID(new AStar());
        MapReader reader;
        int agent_number = 5;
//        reader.load_scenario("room-32-32-4", "random", 25, agent_number);
        reader.load_scenario("empty-8-8", "random", 6, agent_number);

        display_map(reader.get_maps());
        display_problem(reader.get_start_positions(), reader.get_goal_positions());

        solver->set_map(reader.get_maps());
        solver->get_allowed_operations() = vector<pair<Position, HEURISTIC_TYPE> > ({
                                                                                            pair<Position, HEURISTIC_TYPE>(Position(0, 0), 1),
                                                                                            pair<Position, HEURISTIC_TYPE>(Position(0, 1), 1),
                                                                                            pair<Position, HEURISTIC_TYPE>(Position(0, -1), 1),
                                                                                            pair<Position, HEURISTIC_TYPE>(Position(1, 0), 1),
                                                                                            pair<Position, HEURISTIC_TYPE>(Position(-1, 0), 1),
                                                                                    });
        solver->set_problem(reader.get_start_positions(), reader.get_goal_positions());

        solver->solve();
        cout<<solver->get_solution()<<endl;
        for(auto state : solver->get_solution_path())
            cout<<(string)(*state)<<endl;
        cout<<endl;

        solver->solve();
        cout<<solver->get_solution()<<endl;
        for(int i=0; i<agent_number; ++i)
            cout<<i<<"\t:"<<(dynamic_cast<const ID*>(solver)->get_agent_path(i))<<endl;
    }
};


#endif //MAPF_CPP_IDTESTER_H
