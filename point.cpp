//
// Created by Ahmed Ezzat on 2/16/22.
//

#include "point.h"
vector<float> point::coords() {
    return coordinates;
}

float point::distance(point *p2) {
    if(coordinates.size()!=p2->coordinates.size())return -1;
    double sum = 0;
    for (int i = 0 ; i<coordinates.size();i++) {
      sum += pow(abs(coordinates[i]-p2->coordinates[i]),2);
        return sqrt(sum);
    }
}

point::point(vector<float> &coords) {
    coordinates = coords;
}

bool point::inProximity(float tolerance, point * p) {
    float dist= distance(p);
    if(dist<tolerance)return true;
    return false;
}

//point::point(string enc) {
//    if(enc[0]=='p' || enc[0]== 'P') fromWKT(enc);
//    else if(enc[0]=='{') fromGeojson(enc);
//    else throw exception();
//}

string point::asWKT() {
    string wkt = "POINT(";
    for(float c : coordinates){
        wkt+= to_string(c) + " ";
    }
    wkt +=")";
    return wkt;
}

string point::asGeojson() {
    string geojson =  "{\"type\":\"Feature\",\"geometry\":{\"type\":\"Point\",\"coordinates\":[";
    for(float c : coordinates){
        geojson+= to_string(c) + ",";
    }
    geojson.substr(0, geojson.size()-1);
    geojson +="]}}";
    return geojson;
}
