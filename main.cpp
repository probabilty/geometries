#include <iostream>
#include "points/point.h"
#include "pointCloud/pointCloud.h"
#include <unordered_set>
#include "./networks/topology.h"
//int main() {
//    vector<point *> points;
//    //make 10 2D points
//    for (int i = 0; i < 10; ++i) {
//        vector<float> coords;
//        float randx = (float)(rand()%100)/100.0;
//        float randy = (float)(rand()%100)/100.0;
//        coords.push_back(randx);
//        coords.push_back(randy);
//        points.push_back(new point(coords));
//    }
//    //make point cloud
//    pointCloud * pc = new pointCloud(points);
//    cout<<pc->asWKT()<<endl;
//    //cluster them into 2 clusters
//    auto clusters = pc->cluster(3);
//    pointCloud::PrintClusters(clusters);
//    return 0;
//}
int main() {
    unordered_map<string,unordered_set<point *>> network;
    float randx = (float)(rand()%100)/100.0;
    float randy = (float)(rand()%100)/100.0;
    vector<float> coords = {randx,randy};
    point * a = new point(coords,"a");
    randx = (float)(rand()%100)/100.0;
    randy = (float)(rand()%100)/100.0;
    coords = {randx,randy};
    point * b = new point(coords,"b");
    randx = (float)(rand()%100)/100.0;
    randy = (float)(rand()%100)/100.0;
    coords = {randx,randy};
    point * c = new point(coords,"c");
    randx = (float)(rand()%100)/100.0;
    randy = (float)(rand()%100)/100.0;
    coords = {randx,randy};
    point * d = new point(coords,"d");
    network["a"]= unordered_set<point *>{c};
    network["c"]= unordered_set<point *>{d};
    network["d"]= unordered_set<point *>{b,c,a};
    network["b"]= unordered_set<point *>{c};
    topology *t = new topology(network);
//    t->printTopology();
    list route  = t->route("b","a");
    for(string step : route)
        cout<<step<<"-->";
    cout<<"arrived"<<endl;
    return 0;
}