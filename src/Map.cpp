//
// Created by Administrator on 2023/3/4.
//

#include "Map.h"

void Map::initial_map() {
    map_value.assign(map_height, std::vector<GRID_STATE>(map_width, PASSABLE));
}

Map::Map(int map_height_, int map_width_) :map_height(map_height_), map_width(map_width_) {
    initial_map();
}

Map::Map(const Map &other):map_height(other.map_height), map_width(other.map_width), map_value(other.map_value) {
}

int Map::get_height() const {
    return map_height;
}

int Map::get_width() const {
    return map_width;
}

void Map::set_size(int map_height_, int map_width_) {
    map_height = map_height_;
    map_width = map_width_;
    initial_map();
}

std::vector<GRID_STATE> &Map::operator[](int row) {
    if(row < map_height)
        return map_value[row];
    else
        throw "Out of map";
}

const std::vector<GRID_STATE> &Map::operator[](int row) const {
    if(row < map_height)
        return map_value[row];
    else
        throw "Out of map";
}
