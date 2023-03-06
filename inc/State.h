//
// Created by Administrator on 2023/3/5.
//

#ifndef MAPF_CPP_STATE_H
#define MAPF_CPP_STATE_H

#include <stddef.h>

/**
 *
 * An abstract class of search state.
 * It could be hash by its own inner class hasher.
 * And it has been overrode its equal-to operation and not-equal-to operation.
 */
class State {
public:
    /**
     *
     * An abstract class used to hash the outer class.
     */
    class StateHasher {
    public:
        /**
         *
         * @param s outer class state which need to be hash.
         * @return hash value of s.
         */
        virtual size_t operator() (const State& s) const = 0;
    };

    /**
     *
     * @param s another state which is need to detecting equalization.
     * @return true means equal, and false means not equal.
     *
     * It will be detecting by hash value firstly, and then by checking all the other attributes.
     */
    virtual bool equalTo(const State &s) const = 0;

    /**
     *
     * @param s another state which is need to detecting whether they are equal or not.
     * @return true means equal, and false means not equal.
     */
    virtual bool operator == (const State &s) const;

    /**
     *
     * @param s another state which is need to detecting whether they are not equal or not.
     * @return true means not equal, and false means equal.
     */
    virtual bool operator != (const State &s) const;

    /**
     *
     * @return Own hasher of this state class.
     *
     * It will be implemented on sub-class.
     */
    virtual StateHasher & get_hasher() const = 0;

    /**
     *
     * @return a string which describes this state.
     */
    virtual operator std::string() const = 0;
};


#endif //MAPF_CPP_STATE_H
