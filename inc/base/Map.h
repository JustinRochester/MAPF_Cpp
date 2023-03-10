//
// Created by Administrator on 2023/3/4.
//

#ifndef MAPF_CPP_MAP_H
#define MAPF_CPP_MAP_H


#include <vector>
#include "common.h"
#include "Position.h"

/**
 *
 * Represent the detail of grid map in this MAPF problem.\n\n
 * It has the attributes height, width and states(passable or unpassable) of all the grid cells.
 */
class Map {
protected:
    /**
     *
     * Height of this map.
     */
    int map_height;

    /**
     *
     * Width of this map.
     */
    int map_width;

    /**
     *
     * map_value[i][j] means the state(passable of not) of this grid cell (i,j), which is started from (0,0).
     */
    std::vector< std::vector<GRID_STATE> > map_value;

    /**
     *
     * Initialize the map with a all passable grid cells whose size is height * width.
     */
    void initial_map();

public:
    /**
     *
     * @param map_height_ height of this map.
     * @param map_width_ width of this map.
     *
     * Initialize the map with the size map_height_ * map_width_ with all passable grid cells.\n\n
     * Default size is 0 * 0.
     */
    Map(int map_height_=0, int map_width_=0);

    /**
     *
     * @param other source map.
     *
     * Initialize this map as the given source map.
     */
    Map(const Map &other);

    /**
     *
     * @return a integer, which represents height of this map.
     */
    int get_height() const;

    /**
     *
     * @return a integer, which represents width of this map.
     */
    int get_width() const;

    /**
     *
     * @param map_height_ new height of this map.
     * @param map_width_ new width of this map.
     *
     * Resize the map with a new size map_height_ * map_width_ with all passable grid cells.
     */
    void set_size(int map_height_, int map_width_);

    /**
     *
     * @param row which row is selecting.
     * @return the reference of the selecting row.
     *
     * Return the reference of the selecting row, if its under the bound of map's size.\n\n
     * It will throw a exception if the selecting row is out of the bound.
     */
    std::vector<GRID_STATE>& operator [] (int row);

    /**
     *
     * @param row which row is selecting.
     * @return the read-only reference of the selecting row.
     *
     * Return the read-only reference of the selecting row, if its under the bound of map's size.\n\n
     * It will throw a exception if the selecting row is out of the bound.
     */
    const std::vector<GRID_STATE>& operator [] (int row) const;

    /**
     *
     * @param p the position which needs to be checked whether this position is passable.
     * @return true means passable, vice versa.
     */
    bool check_passable(const Position& p) const;
};


#endif //MAPF_CPP_MAP_H
