//
// Created by Administrator on 2023/3/8.
//

#ifndef MAPF_CPP_ASTARTESTER_H
#define MAPF_CPP_ASTARTESTER_H

#include "AStar.h"
#include "Tester.h"
#include "MapReaderTester.h"

class AStarTester : public Tester {
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
        Solver *solver = new AStar();
        MapReader reader;
        reader.load_scenario("room-32-32-4", "random", 3, 2);
//        reader.load_scenario("empty-8-8", "random", 6, 3);

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
        solver->clear_nodes();

        solver->solve();
        cout<<solver->get_solution()<<endl;
        for(auto state : solver->get_solution_path())
            cout<<(string)(*state)<<endl;
        cout<<endl;

        solver->solve();
        cout<<solver->get_solution()<<endl;
        for(auto state : solver->get_solution_path())
            cout<<(string)(*state)<<endl;
        cout<<endl;
    }
};


#endif //MAPF_CPP_ASTARTESTER_H
