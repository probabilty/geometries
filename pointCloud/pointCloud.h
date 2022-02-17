//
// Created by Ahmed Ezzat on 2/17/22.
//

#ifndef POINT_POINTCLOUD_H
#define POINT_POINTCLOUD_H
#include "../points/point.h"
#include <iostream>
class pointCloud {
public:
    pointCloud();
    explicit pointCloud(vector<point *> &points);
    vector<vector<point *>> cluster(int clusters);
    double diameter();
    string asWKT();
    static point * getCentroid(vector<point *> & pointCluster);
    static bool isSameCentroids(vector<point *> & a, vector<point *> & b);
    static void PrintClusters(vector<vector<point *>> clusters);
private:
    vector<point *> points;
    void assignPointsToCentroid(vector<point *> centroids, vector<vector<point *>>& ps);
};
#endif //POINT_POINTCLOUD_H
