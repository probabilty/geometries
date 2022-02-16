//
// Created by Ahmed Ezzat on 2/16/22.
//

#ifndef POINT_POINT_H
#define POINT_POINT_H
#include <vector>
using namespace std;
class point {
public:
    point(vector<float> &coords);
    float distance(point * p2);
    vector<float> coords();
    bool inProximity(float tolerance, point * p);
private:
    vector<float>coordinates;
};


#endif //POINT_POINT_H
