# geometries
lightSyntax geometrical project
please check light sytanx post here for extinsive tutorial
https://lightsyntax.home.blog/2022/02/16/points/

To testing and usage 

```c++
#include <iostream>
#include "point.h"
int main() {
    vector<float> xy = {0,0};
    vector<float> xy2 = {1,1};
    point *p0 = new point(xy);
    point *p1 = new point(xy2);
    std::cout << p1->distance(p0) << std::endl;
    return 0;
}

```
