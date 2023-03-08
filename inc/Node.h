//
// Created by Administrator on 2023/3/5.
//

#ifndef MAPF_CPP_NODE_H
#define MAPF_CPP_NODE_H

#include "common.h"

/**
 *
 * Base class of search node in A* algorithm and its variants.
 */
class Node {
protected:
    /**
     *
     * The cost of path from start node to this node.
     */
    HEURISTIC_TYPE g;

    /**
     *
     * The estimating cost of path from this node to goal node.
     */
    HEURISTIC_TYPE h;

    /**
     *
     * The estimating cost of all path which passes this node.
     */
    HEURISTIC_TYPE static_f;

    /**
     *
     * calculate f value (the estimating cost of all path which passes this node) as f = g + h.
     */
    void calculate_static_f();

public:
    /**
     *
     * @param g_ the cost of path from start node to this node.
     * @param h_ the estimating cost of path from this node to goal node.
     *
     * Initialize this node by setting its g value and h value as g_ and h_.\n\n
     * It will call the calculate_static_f method to calculate f value
     * (the estimating cost of all path which passes this node) automatically.
     */
    Node(const HEURISTIC_TYPE &g_= 0, const HEURISTIC_TYPE &h_= 0);

    /**
     *
     * @param other source node.
     *
     * Initialize this node as the given source node.
     */
    Node(const Node &other);

    /**
     *
     * @param h_ the new estimating cost of path from this node to goal node.
     *
     * Update the h value of this node as h_.
     */
    void set_h(const HEURISTIC_TYPE &h_);

    /**
     *
     * @param g_ the new cost of path from start node to this node.
     *
     * Update the g value of this node as g_.
     */
    void set_g(const HEURISTIC_TYPE &g_);

    /**
     *
     * @return the estimating cost of path from this node to goal node (known as h value).
     */
    const HEURISTIC_TYPE & get_h() const;

    /**
     *
     * @return the cost of path from start node to this node (known as g value).
     */
    const HEURISTIC_TYPE & get_g() const;

    /**
     *
     * @return the estimating cost of all path which passes this node (known as f value).
     */
    const HEURISTIC_TYPE & get_static_f() const;

    /**
     *
     * @param rhs another node which will be compare to.
     * @return a integer in [-1,1].
     *
     * It will compare this node to another node, and returns the less-equal-greater relevant.\n\n
     * It returns -1 if this node has an higher priority than rhs;\n\n
     * It returns 1 if this node has an lower priority than rhs;\n\n
     * It returns 0 if these two nodes have an equal priority.
     */
    virtual int compareTo(const Node &rhs) const;
};


#endif //MAPF_CPP_NODE_H
