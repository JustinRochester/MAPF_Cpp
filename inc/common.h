//
// Created by Administrator on 2023/3/4.
//

#ifndef MAPF_CPP_COMMON_H
#define MAPF_CPP_COMMON_H

/**
 *
 * Represents whether there is passable or not, while reading the map.
 */
typedef bool GRID_STATE;

/**
 *
 * Represents that this grid cell is passable while reading the map.
 */
const GRID_STATE PASSABLE = false;

/**
 *
 * Represents that this grid cell is not passable while reading the map.
 */
const GRID_STATE UNPASSABLE = true;


/**
 * 
 * Describes the number in each axis of position.
 */
typedef int GRID_TYPE;


/**
 *
 * Describes the value of time.
 */
typedef int TIME_TYPE;


/**
 *
 * Describes the value of heuristic function.
 */
typedef double HEURISTIC_TYPE;

/**
 *
 * The precision bound(epsilon, as known as eps), which is used to fixing the floating error.
 */
const HEURISTIC_TYPE eps = 1e-9;

/**
 *
 * @param v: a value which is needed to recognize its sign.
 * @return: the sign of this value.
 *
 * sgn(v) is 1 while v is grater than precision bound(epsilon, as known as eps);\n\n
 * sgn(v) is -1 while v is less than precision bound(eps);\n\n
 * and sgn(v) is 0 while the absolute value of v is less and equal to precision bound(eps).\n\n
 * Since the floating numbers have some little error, we need to recognize their signs by this method.
 */
int sgn(HEURISTIC_TYPE v);

#endif //MAPF_CPP_COMMON_H
