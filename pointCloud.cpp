//
// Created by Ahmed Ezzat on 2/17/22.
//

#include "pointCloud.h"

pointCloud::pointCloud(vector<point *> &points) {
    this->points = points;
}

pointCloud::pointCloud() = default;

point * pointCloud::getCentroid(vector<point *> &pointCluster) {
    if(pointCluster.empty()) {
        vector<float> origin = {0};
        return new point(origin);
    }
    vector<float> centroidCoords = vector<float>(pointCluster[0]->coords().size(),0);
    for (point *p : pointCluster) {
        vector<float> coords = p->coords();
        for (int i = 0;i<coords.size();i++)
            centroidCoords[i]+=coords[i];
    }
    for_each(centroidCoords.begin(),centroidCoords.end(),[&pointCluster](float &x){x/=(float)pointCluster.size();});
    return new point(centroidCoords);
}

double pointCloud::diameter() {
    //for each point combination get the largest distance
    double diameter = 0;
    for (auto i = points.begin();i!= points.end();i++) {
        for(auto j = i+1; j!= points.end();j++){
            double  distance  = (*i)->distance(*j);
            diameter = max(diameter,distance);
        }
    }
    return diameter;
}

vector<vector<point *>> pointCloud::cluster(int clusterCount) {
    //initially assume any points as centroids
    vector<point *> centroids = vector<point *>(points.begin(),points.begin()+clusterCount);
    vector<vector<point *>> clusters = vector<vector<point *>>(clusterCount);
    while (true){
        //assign points to centroids
        clusters = vector<vector<point *>>(clusterCount);
        assignPointsToCentroid(centroids,clusters);
        vector<point *> newCentroids ;
        //update centroids
        for (int i = 0; auto v : clusters) {
            newCentroids.push_back(getCentroid(v));
            i++;
        }
        //break when centroids match prev iteration
        if(isSameCentroids(newCentroids,centroids))break;
        else{
            centroids = newCentroids;
        }
    }
    return clusters;
}

void pointCloud::assignPointsToCentroid(vector<point *> centroids, vector<vector<point *>>&ps) {
    for (int i = 0; i < points.size(); ++i) {
        float bestDistance = INTMAX_MAX;
        int bestCentroid = 0;
        //find the best cluster for it
        for (int j = 0;j<centroids.size();j++) {
            float distance = centroids[j]->distance(points[i]);
            if(bestDistance > distance){
                bestDistance = distance;
                bestCentroid = j;
            }
        }
        ps[bestCentroid].push_back(points[i]);
    }
}

bool pointCloud::isSameCentroids(vector<point *> &a, vector<point *> &b) {
    if(a.size()!=b.size())return false;
    for (int i = 0; i < a.size(); ++i) {
        if(a[i]->inProximity(0.000001,b[i]))continue;
        else return false;
    }
    return true;
}

void pointCloud::PrintClusters(vector<vector<point *>> clusters) {
    for (int i = 0; i < clusters.size(); ++i) {
        cout<< string(5,'-')<<"cluster \""<<i<<"\" points"<< string(5,'-')<<endl;
        for (point * p : clusters[i])
            cout<<p->asWKT()<<endl;
    }
}

string pointCloud::asWKT() {
    string s = "GeometryCollection(";
        for(point * p : points)
            s+=p->asWKT()+",";
        s = s.substr(0,s.size()-1);
    s+=")";
    return s;
}
