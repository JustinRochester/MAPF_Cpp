//
// Created by Administrator on 2023/3/10.
//

#ifndef MAPF_CPP_LEFTISTTREETESTER_H
#define MAPF_CPP_LEFTISTTREETESTER_H

#include "Tester.h"
#include "LeftistTree.h"

class LeftistTreeTester : public Tester {
protected:
    mt19937 rnd;

public:
    LeftistTreeTester():rnd(time(0)) {
    }
    void run() override {
        int n = 10;
        vector<LeftistTree*> v(n, nullptr);
        for(int i=0; i<n; ++i)
            v[i] = new LeftistTree(i);

        int q = 10;
        for(int i=0; i<q; ++i) {
            vector<int> tmp;
            int a = rnd()%10, b = rnd()%10;
            cout<<"merge "<<a<<" "<<b<<endl;
            merge_root(v[a], v[b]);
            tmp = v[a]->get_pre_order();
            cout<<">>> ";
            for(auto e : tmp)
                cout<<e<<" ";
            cout<<endl;
        }
    }
};


#endif //MAPF_CPP_LEFTISTTREETESTER_H
