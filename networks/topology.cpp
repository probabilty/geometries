//
// Created by Ahmed Ezzat on 2/17/22.
//

#include "topology.h"

topology::topology() = default;;


topology::topology(const std::unordered_set<point *>& points) {
    //add the nodes
    for (point *  p : points)
        nodes[p->id]=p;
}

topology::topology(unordered_map<string , unordered_set<point *>> &network) {
    // add the nodes
    for (const auto& pb : network)
        for(auto p : pb.second)
            nodes[p->id]=p;
    //add the network
    for (const auto& pb : network){
        point * src = nodes[pb.first];
        for(point * dst : pb.second)
            this->network[src->id].insert(dst->id);
    }
}

void topology::addNode(point *p) {
    if(!nodes.contains(p->id))
        nodes[p->id]=p;
}

void topology::linkNodeToNode(const string& from, const string& to) {
    if(nodes.contains(from) && nodes.contains(to))
        network[from].insert(to);
}

void topology::linkNodeToMany(const string& from, const vector<string>& to) {
    if(nodes.contains(from) )
        for(const string& p : to)
            if (nodes.contains(p))
                network[from].insert(p);
}

unordered_map<string, unordered_set<string>> topology::getTopology(){
    return network;
}

void topology::removeLink(const string& a, const string& b) {
    if(network.contains(a))
        network[a].erase(b);
}

void topology::printTopology() {
    for (const auto& node : network) {
        for (const string& adj : node.second)
            cout<<node.first <<"-->"<<adj<<endl;
//        cout<<"NULL"<<endl;
    }
}

list<string> topology::route(const string& src, const string& dst) {
    typedef struct path{
        list<string>path;
        string node;
    };
    queue<path> processing;
    unordered_set<string> visited;
    processing.push(path{
        .node = src
    });
    while (!processing.empty()){
        path currentNode = processing.front();
        processing.pop();
        if (visited.contains(currentNode.node))continue;
        visited.insert(currentNode.node);
        currentNode.path.push_back(currentNode.node);
        if (currentNode.node == dst){
            return currentNode.path;
        }
        for (const auto& node : network[currentNode.node]) {
            processing.push(path{
                .path =  currentNode.path,
                .node = node,
            });
        }
    }
}


