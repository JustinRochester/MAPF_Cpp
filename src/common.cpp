//
// Created by Administrator on 2023/3/5.
//

#include "common.h"

int sgn(HEURISTIC_TYPE v) {
    return (v>eps) - (v<-eps);
}