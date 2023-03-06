//
// Created by Administrator on 2023/3/6.
//

#ifndef MAPF_CPP_NODETESTER_H
#define MAPF_CPP_NODETESTER_H

#include "Node.h"
#include "Tester.h"

class NodeTester : public Tester{
public:
    void run() override {
        Node n(1, 2.5), m;
        cout<<n.get_g()<<" "<<n.get_h()<<" "<<n.get_static_f()<<endl;
        cout<<m.get_g()<<" "<<m.get_h()<<" "<<m.get_static_f()<<endl;
        m.set_g(2);
        cout<<m.get_g()<<" "<<m.get_h()<<" "<<m.get_static_f()<<endl;
        m.set_h(0.5);
        cout<<m.get_g()<<" "<<m.get_h()<<" "<<m.get_static_f()<<endl;
        cout<<n.compareTo(m)<<" "<<m.compareTo(n)<<endl;
        m.set_h(1.5);
        cout<<m.get_g()<<" "<<m.get_h()<<" "<<m.get_static_f()<<endl;
        cout<<n.compareTo(m)<<" "<<m.compareTo(n)<<endl;
    }
};


#endif //MAPF_CPP_NODETESTER_H
