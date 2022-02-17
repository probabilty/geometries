cmake_minimum_required(VERSION 3.21)
project(point)

set(CMAKE_CXX_STANDARD 23)

add_executable(point main.cpp points/point.cpp points/point.h pointCloud/pointCloud.cpp pointCloud/pointCloud.h networks/topology.cpp networks/topology.h)
