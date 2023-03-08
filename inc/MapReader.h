//
// Created by Administrator on 2023/3/4.
//

#ifndef MAPF_CPP_MAPREADER_H
#define MAPF_CPP_MAPREADER_H

#include <vector>
#include <string>
#include <fstream>
#include "common.h"
#include "Position.h"
#include "Map.h"

/**
 *
 * @param c character over this grid cell.
 * @return this grid cell is passable or not.
 *
 * Get the state(passable or not) of this grid while the character over this grid cell is c.\n\n
 */
GRID_STATE get_grid_state(char c);

/**
 *
 * A reader for the benchmarks involved in thesis: Stern R, Sturtevant N, Felner A, et al. Multi-agent pathfinding:
 * Definitions, variants, and benchmarks[C]//Proceedings of the International Symposium on Combinatorial Search.
 * 2019, 10(1): 151-158.\n\n
 * Benchmarks is download from address: https://movingai.com/benchmarks/mapf.html,
 * and format is setting in https://movingai.com/benchmarks/formats.html.
 */
class MapReader {
protected:
    /**
     *
     * Detail of the reading map.
     */
    Map maps;

    /**
     *
     * An array list describes the start positions for all the agents.
     */
    std::vector<Position> start_positions;

    /**
     *
     * An array list describes the goal positions for all the agents.
     */
    std::vector<Position> goal_positions;

    /**
     *
     * @param map_fin in-file-stream using to reading map.
     *
     * Used in load_scenario method. Detail of the map will be stored in the attribute map.
     */
    void read_map(std::ifstream &map_fin);

    /**
     *
     * @param scen_fin in-file-stream using to reading scenario(including start and goal positions for each agent).
     * @param agents_number number of agents we will reading.
     *
     * Used in load_scenario method. It will read the start positions and goal positions for the first agents_number
     * agents.
     */
    void read_scenario(std::ifstream &scen_fin, int agents_number);

public:
    /**
     *
     * Initialize this map with an empty map, an empty start_positions and an empty goal_positions.
     */
    MapReader();

    /**
     *
     * @param other source map reader.
     *
     * Initialize this map reader as the given source map reader.
     */
    MapReader(const MapReader &other);

    /**
     *
     * @param map_name name of map, for example: "Berlin_1_256";
     * @param type "even" or "random";
     * @param scen_name_id id of the scenario about this map. It should be ensured that id is in [1,25];
     * @param problem_id id of the problem about this scenario, measured by the number of agent.
     * It should be ensured that id is in [1,1000];
     *
     * Load a scenario whose filename is [scen_filename]=[map_name]-[type]-[scen_name_id].scen.\n\n
     * Scenario is in the directory: scen/scen-[type]/[scen_filename].\n\n
     * Map is in the directory: scen/mapf-map/[map_filename], where [map_filename]=[map_name].map.\n\n
     * This method will load this scenario with problem_id as the number of agents.\n\n
     */
    void load_scenario(std::string map_name, std::string type, int scen_name_id, int problem_id);

    /**
     *
     * @return the number of agents.
     */
    int get_agent_number() const;

    /**
     *
     * @return the read-only reference of start_positions array list.
     */
    const std::vector<Position> & get_start_positions() const;

    /**
     *
     * @return the read-only reference of goal_positions array list.
     */
    const std::vector<Position> & get_goal_positions() const;

    /**
     *
     * @return the read-only reference of map details.
     */
    const Map & get_maps() const;
};


#endif //MAPF_CPP_MAPREADER_H
