//
// Created by Administrator on 2023/3/7.
//

#ifndef MAPF_CPP_ASTARNODETESTER_H
#define MAPF_CPP_ASTARNODETESTER_H

#include "Tester.h"
#include "AStarNode.h"

class AStarNodeTester : public Tester {
public:
    void display(const AStarNode &node) {
        cout<<node.get_g()<<" "<<node.get_h()<<" "<<node.get_static_f()<<endl;
        cout<<node.get_state()<<endl;
    }
    void run() override {
        AStarNode node(1, 5, 0);
        node.get_state().set_time(3);
        node.get_state().get_positions() = vector<Position>({Position(3, 2), Position(1, 5)});
        display(node);
        cout<<endl;

        node = node.apply(vector<pair<Vector, HEURISTIC_TYPE> >({
            pair<Vector, HEURISTIC_TYPE>(Vector(1,1), 2),
            pair<Vector, HEURISTIC_TYPE>(Vector(1,-3), 3)
        }));
        display(node);

        cout<<node[0]<<" "<<node[1]<<endl;
    }
};


#endif //MAPF_CPP_ASTARNODETESTER_H
