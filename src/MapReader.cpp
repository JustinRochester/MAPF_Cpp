//
// Created by Administrator on 2023/3/4.
//

#include "MapReader.h"
#include <io.h>
#include <fstream>

GRID_STATE get_grid_state(char c) {
    if(c=='.' || c=='G' || c=='S')
        return PASSABLE;
    else
        return UNPASSABLE;
}

MapReader::MapReader() {
    start_positions.clear();
    goal_positions.clear();
}

void MapReader::read_map(std::ifstream &map_fin) {
    std::string s;
    int height, width;
    map_fin>>s;
    map_fin>>s;
    map_fin>>s>>height;
    map_fin>>s>>width;
    map_fin>>s;

    maps.set_size(height, width);
    for(int i=0; i<height; ++i) {
        map_fin>>s;
        std::vector<GRID_STATE> &now = maps[i];
        for(int j=0; j<width; ++j)
            now[j] = get_grid_state(s[j]);
    }
}

void MapReader::read_scenario(std::ifstream &scen_fin, int agents_number) {
    std::string s;
    int version;
    scen_fin>>s>>version;

    int bucket, width, height, start_x, start_y, goal_x, goal_y;
    double optimal_length;

    start_positions.clear();
    goal_positions.clear();
    for(int i=0; i < agents_number; ++i) {
        scen_fin >> bucket >> s >> width >> height >> start_x >> start_y >> goal_x >> goal_y >> optimal_length;
        start_positions.emplace_back(start_x, start_y);
        goal_positions.emplace_back(goal_x, goal_y);
    }
}

void MapReader::load_scenario(std::string map_name, std::string type, int scen_name_id, int problem_id) {
    std::string scen_directory = "../scen/scen-" + type;
    std::string scen_filename = map_name + "-" + type + "-" + std::to_string(scen_name_id) + ".scen";

    std::string map_directory = "../scen/mapf-map";
    std::string map_filename = map_name + ".map";

    if(_access(scen_directory.c_str(), 0) == -1)
        throw "scenario directory is not exists!";
    if(_access(map_directory.c_str(), 0) == -1)
        throw "map directory is not exists!";

    std::ifstream scen_fin, map_fin;
    scen_fin.open((scen_directory + "/" + scen_filename).c_str());
    map_fin.open((map_directory + "/" + map_filename).c_str());

    if(!scen_fin)
        throw "scenario file is not exists!";
    if(!map_fin)
        throw "map file is not exists!";

    read_map(map_fin);
    read_scenario(scen_fin, problem_id);
}

const std::vector<Position> & MapReader::get_start_positions() const {
    return start_positions;
}

const std::vector<Position> & MapReader::get_goal_positions() const {
    return goal_positions;
}

const Map & MapReader::get_maps() const {
    return maps;
}

int MapReader::get_agent_number() const {
    return start_positions.size();
}
