//
// Created by Ahmed Ezzat on 2/17/22.
//

#ifndef POINT_TOPOLOGY_H
#define POINT_TOPOLOGY_H
#include <unordered_set>
#include <unordered_map>
#include <list>
#include <iostream>
#include <queue>
#include "../points/point.h"
class topology {
public:
    topology();
    explicit topology(const std::unordered_set<point *>& points);
    explicit topology(unordered_map<string,unordered_set<point *>> &network);
    void addNode(point * p);
    void linkNodeToNode(const string& from, const string& to);
    void linkNodeToMany(const string& from, const vector<string>& to);
    unordered_map<string, unordered_set<string>> getTopology();
    void removeLink(const string& a, const string& b);
    void printTopology();
    list<string> route(const string& src, const string& dst);
private:
    unordered_map<string, unordered_set<string>> network;
    unordered_map<string, point *> nodes;
};
#endif //POINT_TOPOLOGY_H
