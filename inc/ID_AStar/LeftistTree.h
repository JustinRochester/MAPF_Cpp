//
// Created by Administrator on 2023/3/10.
//

#ifndef MAPF_CPP_LEFTISTTREE_H
#define MAPF_CPP_LEFTISTTREE_H


class LeftistTree {
protected:
    int value;
    LeftistTree* parent;
    LeftistTree* left_child;
    LeftistTree* right_child;
    int distance;

public:
    LeftistTree(int value);

    LeftistTree(const LeftistTree& other);

    int get_value() const;

    void set_value(int value);

    LeftistTree *get_parent() const;

    void set_parent(LeftistTree *parent);

    LeftistTree *get_left_child() const;

    void set_left_child(LeftistTree *leftChild);

    LeftistTree *get_right_child() const;

    void set_right_child(LeftistTree *rightChild);

    int get_distance() const;

    void set_distance(int distance);

    LeftistTree* get_root();

    const LeftistTree* get_root() const;

    friend LeftistTree* merge(LeftistTree *x, LeftistTree *y);

    friend LeftistTree* merge_root(LeftistTree *x, LeftistTree *y);

    std::vector<int> get_pre_order() const;
};


#endif //MAPF_CPP_LEFTISTTREE_H
