//
// Created by Administrator on 2023/3/5.
//

#include "Node.h"

Node::Node(const HEURISTIC_TYPE &g_, const HEURISTIC_TYPE &h_): g(g_), h(h_) {
    calculate_static_f();
}

void Node::calculate_static_f() {
    static_f = g+h;
}

void Node::set_h(const HEURISTIC_TYPE &h_) {
    h = h_;
    calculate_static_f();
}

void Node::set_g(const HEURISTIC_TYPE &g_) {
    g = g_;
    calculate_static_f();
}

const HEURISTIC_TYPE & Node::get_h() const {
    return h;
}

const HEURISTIC_TYPE & Node::get_g() const {
    return g;
}

const HEURISTIC_TYPE & Node::get_static_f() const {
    return static_f;
}

int Node::compareTo(const Node &rhs) const {
    return sgn(static_f - rhs.static_f);
}