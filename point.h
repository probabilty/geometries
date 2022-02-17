//
// Created by Ahmed Ezzat on 2/16/22.
//

#ifndef POINT_POINT_H
#define POINT_POINT_H
#include <vector>
#include <string>
using namespace std;
class point {
public:
    point(vector<float> &coords);
    //geojson or wkt
    point(string enc);
    float distance(point * p2);
    vector<float> coords();
    bool inProximity(float tolerance, point * p);
    string asGeojson();
    string asWKT();
private:
    vector<float>coordinates;
    void fromGeojson(string p);
    void fromWKT(string p);
};


#endif //POINT_POINT_H
