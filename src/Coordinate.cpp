#include "Coordinate.h"
#include "Board.h"
#include <algorithm>
Coordinate::Coordinate(int n) : n(n), i(0), j(0) {
    this->n = n; 
}

Coordinate::Coordinate(int i, int j, int n) : i(i), j(j), n(n) {

}

std::vector<std::pair<Coordinate, Direction>> Coordinate::getNeighbors() {
    std::vector<std::pair<Coordinate, Direction>> res;
    if(i > 0) res.push_back({{i - 1, j, n}, N});
    if(j > 0) res.push_back({{i, j - 1, n}, W});
    if(i < n - 1) res.push_back({{i + 1, j, n}, S});
    if(j < n - 1) res.push_back({{i, j + 1, n}, E});
    return res;
}