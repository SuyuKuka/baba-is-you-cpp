#ifndef _MAP
#define _MAP
#include <iostream>

class Map {
private: 
    int height;
    int width;
    friend class MapParser;
public: 
    Map(int width, int height) : width(width), height(height) {
        
    }
};

#endif