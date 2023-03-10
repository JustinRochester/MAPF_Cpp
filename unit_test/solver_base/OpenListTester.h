//
// Created by Administrator on 2023/3/7.
//

#ifndef MAPF_CPP_OPENLISTTESTER_H
#define MAPF_CPP_OPENLISTTESTER_H

#include "Tester.h"
#include "OpenList.h"
#include "AStarNode.h"

class OpenListTester : public Tester {
public:
    void display(const AStarNode &node) {
        cout<<node.get_g()<<" "<<node.get_h()<<" "<<node.get_static_f()<<endl;
        cout<<node.get_state()<<endl;
    }
    void run() override {
        OpenList open;
        AStarNode node1(3, 5, 0), node2(4, 2, 0);
        node1.get_state().get_positions().get_position_list() = vector<Position> ({
            Position(2, 3),
            Position(3, 5)
        });
        node1.get_state().set_time(3);

        node2.get_state().get_positions().get_position_list() = vector<Position> ({
                 Position(-1, -1),
                 Position(2, 6)
         });
        node2.get_state().set_time(5);

        open.push_safe(&node1);
        open.push_safe(&node2);
//        open.push(new AStarNode(node1));
//        open.push(new AStarNode(node2));
        auto now = open.top_safe<AStarNode>();
//        auto now = new AStarNode(*dynamic_cast<const AStarNode*>(open.top()));
        display(*now); cout<<endl;
        open.pop();
        now = open.top_safe<AStarNode>();
//        now = new AStarNode(*dynamic_cast<const AStarNode*>(open.top()));
        display(*now); cout<<endl;
    }
};


#endif //MAPF_CPP_OPENLISTTESTER_H
