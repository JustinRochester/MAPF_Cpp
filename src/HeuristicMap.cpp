//
// Created by Administrator on 2023/3/4.
//

#include "HeuristicMap.h"
#include <queue>

HeuristicMap::HeuristicMap() {
    h_val.clear();
}

void HeuristicMap::calculate_heuristic(const Map &maps, const Position &goal,
                                       const std::vector<std::pair<Vector, HEURISTIC_TYPE>> &allowed_operations) {
    int height = maps.get_height(), width = maps.get_width();
    std::vector< std::vector<bool> > vised(height, std::vector<bool>(width, false));
    h_val.assign(height, std::vector<HEURISTIC_TYPE>(width, 1.0 / 0.0));

    std::queue<Position> q;
    q.push(goal);
    vised[goal.gety()][goal.getx()] = true;
    h_val[goal.gety()][goal.getx()] = 0;

    while(!q.empty()) {
        Position now_position = q.front();
        q.pop();
        HEURISTIC_TYPE now_h = h_val[now_position.gety()][now_position.getx()];
        for(auto [move, cost] : allowed_operations) {
            Position new_position = now_position + move;
            if(new_position.gety() < 0 || new_position.gety() >= height)
                continue;
            if(new_position.getx() < 0 || new_position.getx() >= width)
                continue;
            if(maps[new_position.gety()][new_position.getx()])
                continue;
            if(vised[new_position.gety()][new_position.getx()])
                continue;
            vised[new_position.gety()][new_position.getx()] = true;
            h_val[new_position.gety()][new_position.getx()] = now_h + cost;
            q.push(new_position);
        }
    }
}

std::vector<HEURISTIC_TYPE> &HeuristicMap::operator[](int row) {
    if(row < h_val.size())
        return h_val[row];
    else
        throw "Out of graph";
}

const std::vector<HEURISTIC_TYPE> &HeuristicMap::operator[](int row) const {
    if(row < h_val.size())
        return h_val[row];
    else
        throw "Out of graph";
}
