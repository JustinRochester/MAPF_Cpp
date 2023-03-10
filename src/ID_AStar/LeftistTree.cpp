//
// Created by Administrator on 2023/3/10.
//

#include <algorithm>
#include <stack>
#include "LeftistTree.h"

LeftistTree::LeftistTree(int value) : value(value), parent(nullptr), left_child(nullptr), right_child(nullptr),
                                      distance(1) {
}

LeftistTree::LeftistTree(const LeftistTree &other) : value(other.value), parent(other.parent),
                                                     left_child(other.left_child), right_child(other.right_child),
                                                     distance(other.distance) {
}

int LeftistTree::get_value() const {
    return value;
}

void LeftistTree::set_value(int value) {
    LeftistTree::value = value;
}

LeftistTree *LeftistTree::get_parent() const {
    return parent;
}

void LeftistTree::set_parent(LeftistTree *parent) {
    LeftistTree::parent = parent;
}

LeftistTree *LeftistTree::get_left_child() const {
    return left_child;
}

void LeftistTree::set_left_child(LeftistTree *leftChild) {
    left_child = leftChild;
}

LeftistTree *LeftistTree::get_right_child() const {
    return right_child;
}

void LeftistTree::set_right_child(LeftistTree *rightChild) {
    right_child = rightChild;
}

int LeftistTree::get_distance() const {
    return distance;
}

void LeftistTree::set_distance(int distance) {
    LeftistTree::distance = distance;
}

LeftistTree *LeftistTree::get_root() {
    LeftistTree *root = this;
    while(root->parent != nullptr)
        root = root->parent;
    return root;
}

const LeftistTree *LeftistTree::get_root() const {
    const LeftistTree *root = this;
    while(root->parent != nullptr)
        root = root->parent;
    return root;
}

LeftistTree *merge(LeftistTree *x, LeftistTree *y) {
    if(x == nullptr) return y;
    if(y == nullptr) return x;
    if(x == y) return x;

    if(x->value > y->value)
        std::swap(x, y);

    x->right_child = merge(x->right_child, y);
    x->right_child->parent = x;
    if(x->left_child == nullptr || x->left_child->distance < x->right_child->distance)
        std::swap(x->left_child, x->right_child);

    if(x->right_child == nullptr)
        x->distance = 1;
    else
        x->distance = x->right_child->distance + 1;
    x->parent = nullptr;
    return x;
}

LeftistTree *merge_root(LeftistTree *x, LeftistTree *y) {
    return merge(x->get_root(), y->get_root());
}

std::vector<int> LeftistTree::get_pre_order() const {
    std::stack<const LeftistTree*> stk;
    std::vector<int> result;

    stk.push(get_root());
    while(!stk.empty()) {
        const LeftistTree* now_node = stk.top();
        stk.pop();
        result.push_back(now_node->value);

        if(now_node->left_child != nullptr)
            stk.push(now_node->left_child);
        if(now_node->right_child != nullptr)
            stk.push(now_node->right_child);
    }
    return result;
}
