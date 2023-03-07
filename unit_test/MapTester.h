//
// Created by Administrator on 2023/3/7.
//

#ifndef MAPF_CPP_MAPTESTER_H
#define MAPF_CPP_MAPTESTER_H

#include "Map.h"
#include "Tester.h"

class MapTester : public Tester{
public:
    void run() override {
        Map m1(4, 3), m2;
        cout<<m1.get_width()<<" "<<m1.get_height()<<endl;
        cout<<m2.get_width()<<" "<<m2.get_height()<<endl;
        m2.set_size(3, 4);
        cout<<m2.get_width()<<" "<<m2.get_height()<<endl;

        m1[3][2]=true;
        for(int i=0; i<m1.get_height(); ++i)
            for(int j=0; j<m1.get_width(); ++j)
                cout<<m1[i][j]<<" \n"[j==m1.get_width()-1];
        cout<<endl;

        m1.set_size(4, 3);
        for(int i=0; i<m1.get_height(); ++i)
            for(int j=0; j<m1.get_width(); ++j)
                cout<<m1[i][j]<<" \n"[j==m1.get_width()-1];
        cout<<endl;

        m2[3][2]=true;
        for(int i=0; i<m2.get_height(); ++i)
            for(int j=0; j<m2.get_width(); ++j)
                cout<<m2[i][j]<<" \n"[j==m1.get_width()-1];
        cout<<endl;
    }
};


#endif //MAPF_CPP_MAPTESTER_H
