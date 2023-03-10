//
// Created by Administrator on 2023/3/5.
//

#ifndef MAPF_CPP_OPENLIST_H
#define MAPF_CPP_OPENLIST_H

#include <queue>
#include <vector>
#include "Node.h"
#include <string>

/**
 *
 * A comparer in nodes which is in open list.
 */
class OpenListComparer {
public:
    /**
     *
     * @param a the first node and its timestamp.
     * @param b the second node and its timestamp.
     * @return true means that a has an higher priority than b, vice versa.
     *
     * It compares a and b by the method compareTo, firstly.\n\n
     * It will return the priority directly if compareTo method returns a inequality about this two nodes.\n\n
     * Otherwise, it will follow the FIFO policy and give a higher priority for the early node
     * by checking their timestamps.
     */
    bool operator () (const std::pair<Node*, int> &a, const std::pair<Node*, int> &b);
};

/**
 *
 * A class simulates the open list.\n\n
 * It will compare two node by node priority and time one by one.
 */
class OpenList {
protected:
    /**
     *
     * It stores the current number of nodes which has been push into this open list.
     */
    int timestamp;

    /**
     *
     * It stores pointers of the current nodes, and could get the best one.
     */
    std::priority_queue<
            std::pair<Node*, int>,
            std::vector< std::pair<Node*, int> >,
            OpenListComparer
    > open_priority_queue;

public:
    /**
     *
     * Initialize the open list as an empty priority queue, and set the timestamp with value 0.
     */
    OpenList();

    /**
     *
     * @param other source open list.
     *
     * Initialize this open list as the given source open list.
     */
    OpenList(const OpenList &other);

    /**
     *
     * Delete all the node pointer in the open list.
     */
    ~OpenList();

    /**
     *
     * @param node the node which will be pushed into this list.
     *
     * It will push this node into the open list with a timestamp.\n\n
     * Please push a new pointer node, like 'push(new XXXNode(yyy))'.
     */
    void push(Node *node);

    /**
     *
     * @tparam T a subclass of Node.
     * @param node the node with class T which will be pushed into this list.
     *
     * Safe mode of push.\n\n
     * It will throw a exception if T isn't a subclass of Node.
     */
    template<class T>
    void push_safe(const T *node) {
        try {
            push(new T(*node));
        }
        catch(const char *msg) {
            std::string s = msg;
            s += "\nIt isn't a sub-class of Node.";
            throw s.c_str();
        }
    }

    /**
     *
     * @return the read-only pointer to the node with the highest priority.
     *
     * To avoid segment fault because of deleting this pointer.\n\n
     * Please creating a new pointer node, like 'auto newnode = new XXXNode(*dynamic_cast<const XXXNode *>(top()))'
     */
    const Node* top() const;

    /**
     *
     * @tparam T a subclass of Node.
     * @return the read-only pointer to the node with a class as T.
     *
     * Safe mode of top.\n\n
     * It will throw a exception if T isn't a subclass of Node, or empty.
     */
    template<class T>
    const T * top_safe() const {
        if(empty())
            throw "the open list is empty";

        try {
            return new T(*dynamic_cast<const T *>(top()));
        }
        catch(const char *msg) {
            std::string s = msg;
            s += "\nIt isn't a sub-class of Node.";
            throw s.c_str();
        }
    }

    /**
     *
     * Pop the node with the highest priority and delete it automatically.
     */
    void pop();

    /**
     *
     * @return true means that this open list is empty, vice versa.
     */
    bool empty() const;

    /**
     *
     * @return the number of pointer this open list stored.
     */
    int size() const;
};


#endif //MAPF_CPP_OPENLIST_H
