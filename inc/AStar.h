//
// Created by Administrator on 2023/3/4.
//

#ifndef MAPF_CPP_ASTAR_H
#define MAPF_CPP_ASTAR_H

#include <vector>
#include <unordered_set>
#include "Solver.h"
#include "HeuristicMap.h"
#include "AStarNode.h"
#include "OpenList.h"
#include "CloseList.h"
#include "PositionList.h"

class AStar : public Solver{
protected:
    std::vector<HeuristicMap> heuristic_maps;
    OpenList open;
    CloseList close;

    void expand_child_nodes(const AStarNode *node);

    void search_moves(AStarNode *node, int agent_id,
                      std::unordered_set<PositionList, PositionList::PositionListHasher> reservation_table);

public:
    AStar();

    void calculate_heuristic(AStarNode *node) const;

    bool expand_nodes(Node *node) override;

    bool generate_nodes(Node *node) override;

    void
    set_problem(const std::vector<Position> &start_positions_, const std::vector<Position> &goal_positions_) override;

    void solve() override;

    bool is_goal_node(const Node *node) const override;
};


#endif //MAPF_CPP_ASTAR_H