//
// Created by Administrator on 2023/3/4.
//

#ifndef MAPF_CPP_HEURISTICMAP_H
#define MAPF_CPP_HEURISTICMAP_H

#include <vector>
#include "common.h"
#include "Position.h"
#include "Map.h"

/**
 *
 * An grid-cell map with a heuristic value in each grid cells.
 */
class HeuristicMap {
protected:
    /**
     *
     * h_val[i][j] means the heuristic value of the cell which is located in (i,j).
     */
    std::vector< std::vector<HEURISTIC_TYPE> > h_val;

public:
    /**
     *
     * Initialize the heuristic map with a empty size(height = width = 0).
     */
    HeuristicMap();

    /**
     *
     * @param maps detail information about this map.
     * @param goal position of this single goal position.
     * @param allowed_movements the allowed movements and its cost in this task.
     *
     * Calculate the heuristic in all the passable grid with the map_value and the single goal position.
     * It should be ensured that goal position is passable.
     */
    void calculate_heuristic(const Map &maps, const Position &goal,
                             const std::vector<std::pair<Vector, HEURISTIC_TYPE>> &allowed_operations);

    /**
     *
     * @param row which row of this heuristic map is selected.
     * @return the reference of the selected row.
     *
     * It will throw an exception if the selected row is out of the bound.
     */
    std::vector<HEURISTIC_TYPE>& operator [] (int row);

    /**
     *
     * @param row which row of this heuristic map is selected.
     * @return the read-only reference of the selected row.
     *
     * It will throw an exception if the selected row is out of the bound.
     */
    const std::vector<HEURISTIC_TYPE>& operator [] (int row) const;
};


#endif //MAPF_CPP_HEURISTICMAP_H
