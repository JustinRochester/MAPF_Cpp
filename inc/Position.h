//
// Created by Administrator on 2023/3/4.
//

#ifndef MAPF_CPP_POSITION_H
#define MAPF_CPP_POSITION_H


#include <string>
#include <cstddef>
#include <functional>
#include <iostream>
#include "common.h"

/**
 *
 * Describes the physics position.
 */
class Position {
protected:
    /**
     * First axis in describing.
     */
    GRID_TYPE y;

    /**
     * Second axis in describing.
     */
    GRID_TYPE x;

public:
    /**
     *
     * @param y_ first axis value.
     * @param x_ second axis value.
     *
     * Initialize the position as (x,y).
     */
    Position(const GRID_TYPE &y_= -1, const GRID_TYPE &x_= -1);

    /**
     *
     * @param y_ new first axis value.
     *
     * Update value of first axis(y) to y_.
     */
    void sety(const GRID_TYPE &y_);

    /**
     *
     * @param x_ new second axis value.
     *
     * Update value of second axis(x) to x_.
     */
    void setx(const GRID_TYPE &x_);

    /**
     *
     * @return a read-only reference of current y.
     */
    const GRID_TYPE & gety() const;

    /**
     *
     * @return a read-only reference of current x.
     */
    const GRID_TYPE & getx() const;

    /**
     *
     * @param lhs the first position which need to be detected their equality.
     * @param rhs the second position which need to be detected their equality.
     * @return true means equal, and false means not equal.
     */
    friend bool operator == (const Position &lhs, const Position &rhs);

    /**
     *
     * @param lhs the first position which need to be detected their inequality.
     * @param rhs the second position which need to be detected their inequality.
     * @return true means not equal, and false means equal.
     */
    friend bool operator != (const Position &lhs, const Position &rhs);

    /**
     *
     * @return a string describing the current position.
     */
    operator std::string() const;

    /**
     *
     * @param out a reference of out-stream.
     * @param p the position which is need to be outputted.
     * @return the origin reference of out-stream.
     *
     * It will transform this position to string, so that it is easy to output.
     */
    friend std::ostream& operator << (std::ostream& out, const Position &p);

    /**
     *
     * @param in a reference of in-stream.
     * @param p the position which is need to be inputted.
     * @return the origin reference of in-stream.
     *
     * It will read the x and y for p, one by one.
     */
    friend std::istream& operator >> (std::istream& in, Position &p);

    /**
     *
     * @param rhs the vector which will be applied to this position.
     * @return the reference of updated position.
     *
     * Position will apply this vector by adding its x and y independently.
     */
    Position& operator += (const Position &rhs);

    /**
     *
     * @param rhs the vector which will be applied to this position.
     * @return the reference of updated position.
     *
     * Position will apply this vector by subtracting its x and y independently.
     */
    Position& operator -= (const Position &rhs);

    /**
     *
     * @param rhs the vector which will be applied to this position.
     * @return the value of new position.
     *
     * Position will apply this vector by adding its x and y independently.
     */
    Position operator + (const Position &rhs) const;

    /**
     *
     * @param rhs the vector which will be applied to this position.
     * @return the value of new position.
     *
     * Position will apply this vector by subtracting its x and y independently.
     */
    Position operator - (const Position &rhs) const;

    /**
     * A hasher which will hash position to get a hash value.
     */
    class PositionHasher {
    public:
        /**
         *
         * @param p position which will need to got its hash value.
         * @return hash value of position p.
         */
        size_t operator () (const Position &p);
    };
};

/**
 *
 * A vector with the same dimension like position.\n\n
 * Describes the physics position.
 */
typedef Position Vector;

#endif //MAPF_CPP_POSITION_H
