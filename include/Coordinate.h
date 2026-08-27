
#include <vector>
#include "Board.h"
#ifndef COORDINATE
#define COORDINATE
class Coordinate {
private:
    int i, j; 
    int n;
public:
    int get_i()const {return i;}
    int get_j() const{return j;}
    
    Coordinate(int n =1000);
    Coordinate(int i, int j, int n = 1000); 
    std::vector<std::pair<Coordinate, Direction>>getNeighbors();
};
#endif 