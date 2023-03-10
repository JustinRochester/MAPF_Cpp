//
// Created by Administrator on 2023/3/10.
//

#ifndef MAPF_CPP_LEFTISTTREE_H
#define MAPF_CPP_LEFTISTTREE_H


class LeftistTree {
protected:
    /**
     *
     * value attribute in heap.
     */
    int value;

    /**
     *
     * pointer to its parent leftist-tree-node.
     */
    LeftistTree* parent;

    /**
     *
     * pointer to its left child leftist-tree-node.
     */
    LeftistTree* left_child;

    /**
     *
     * pointer to its right-child leftist-tree-node.
     */
    LeftistTree* right_child;

    /**
     *
     * distance to its nearest nil node.
     */
    int distance;

public:
    /**
     *
     * @param value the value of its heap's attribute
     *
     * Initialize this leftist-tree-node with given attribute and none of its parent or childs.
     */
    LeftistTree(int value=0);

    /**
     *
     * @param other source leftist-tree-node.
     *
     * Initialize this leftist-tree-node as the given source leftist-tree-node.
     */
    LeftistTree(const LeftistTree& other);

    /**
     *
     * @return value of its heap's attribute
     */
    int get_value() const;

    /**
     *
     * @param value new value which will be set to its heap's attribute.
     */
    void set_value(int value);

    /**
     *
     * @return pointer to its parent leftist-tree-node.
     */
    LeftistTree *get_parent() const;

    /**
     *
     * @param parent new pointer which will be set as its parent leftist-tree-node.
     */
    void set_parent(LeftistTree *parent);

    /**
     *
     * @return pointer to its left child leftist-tree-node.
     */
    LeftistTree *get_left_child() const;

    /**
     *
     * @param leftChild new pointer which will be set as its left child leftist-tree-node.
     */
    void set_left_child(LeftistTree *leftChild);

    /**
     *
     * @return pointer to its right child leftist-tree-node.
     */
    LeftistTree *get_right_child() const;

    /**
     *
     * @param rightChild new pointer which will be set as its right child leftist-tree-node.
     */
    void set_right_child(LeftistTree *rightChild);

    /**
     *
     * @return pointer of the root leftist-tree-node for this set.
     */
    LeftistTree* get_root();

    /**
     *
     * @return read-only pointer of root leftist-tree-node for this set.
     */
    const LeftistTree* get_root() const;

    /**
     *
     * @param x the first leftist-tree-node which will be merged.
     * @param y the second leftist-tree-node which will be merged.
     * @return a new leftist-tree-node which is merged by the given two leftist-tree-nodes.
     *
     * It will happen nothing if one of x or y is nullptr, or x is y.
     */
    friend LeftistTree* merge(LeftistTree *x, LeftistTree *y);

    /**
     *
     * @param x the first set which will be merged.
     * @param y the second set which will be merged.
     * @return a new set which is merged by the given two sets.
     *
     * It is different from method merge by calling get_root method before merge.\n\n
     * It will happen nothing if one of x or y is nullptr, or x is y.
     */
    friend LeftistTree* merge_root(LeftistTree *x, LeftistTree *y);

    /**
     *
     * @return a array list of value for each leftist-tree-node in this set ordered by pre-order.
     */
    std::vector<int> get_pre_order() const;
};


#endif //MAPF_CPP_LEFTISTTREE_H
