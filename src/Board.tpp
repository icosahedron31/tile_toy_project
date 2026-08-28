#include "Board.h"
#include <vector>
#include <memory>
#include <algorithm>
#include <assert.h>
#include <iostream>
template<typename T>
Board<T>::Board(int n, std::vector<std::vector<Tile<T>>>initial) :n(n), empty_tile({0, 0, n}) {
    assert(initial.size() == n);
    assert(std::all_of(initial.begin(), initial.end(), 
    [n](std::vector<Tile<T>>v)->bool{
        return v.size() == n;
    }));   
    this->tiles = std::move(initial);
   
}
template<typename T> 
Coordinate Tile<T>::getCoordinate() {
    return co;
}
template<typename T> 
Tile<T> Board<T>::getTile(int i, int j) { 
    return this->tiles[i][j];
}
template<typename T> 
void Board<T>::makeMove(Direction d) { 
    int empty_x =  empty_tile.get_i(), empty_y = empty_tile.get_j();
    int target_x, target_y;
    if(d == W) { 
        target_x = empty_x, target_y = empty_y + 1;
    }
    if(d == E) {
        target_x = empty_x, target_y = empty_y - 1; 
    }
    if(d == S) {
        target_x = empty_x - 1, target_y = empty_y;
    }
    if(d == N) {
        target_x = empty_x + 1, target_y = empty_y;
    }

    swap(tiles[empty_x][empty_y].isEmpty, tiles[target_x][target_y].isEmpty);
    swap(tiles[empty_x][empty_y].value, tiles[target_x][target_y].value);
    empty_tile = {target_x, target_y, n};

}


template<typename T> 
void Board<T>::print() {
    for(const auto & line : this->tiles) {
        for(const auto & v : line) {
            std::cout << v.value << ' ';
        }
        std::cout << '\n';
    }
  
}
template<typename T>
bool Brain<T>::isMovePossible(const Board<T> * board, const Direction d) {
    if(d == N && board->empty_tile.get_i() == board->n - 1) {
        return false; 
    } 
    if(d == S && board->empty_tile.get_i() == 0) {
        return false; 
    }
    if(d == W && board->empty_tile.get_j() == board->n - 1) {
        return false; 
    }
    if(d == E && board->empty_tile.get_j() == 0) {
        return false; 
    }
    return true;
}

template<typename T>
std::vector<Direction> Brain<T>::getPossibleDirections(const Board<T>*board) {
    Tile<T> x = board->tiles[board->empty_tile.get_i()][board->empty_tile.get_j()];
    std::vector<std::pair<Coordinate, Direction>> neighbors = x.getCoordinate().getNeighbors();
    std::vector<Direction>possible_directions;
    for(const auto & to : neighbors) {
        possible_directions.push_back(-to.second);
    }
    return possible_directions;
}