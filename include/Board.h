#ifndef BOARD_H
#define BOARD_H
#include <vector>
#include <iostream>
#include "Direction.h"

#include "Coordinate.h"

template<typename T>
struct Tile {
    bool isEmpty; 
    T value;
    Coordinate co;
    Tile() = default;
    Tile(T value) : value(value) {
        co = {0, 0};
        isEmpty = false;
    }
    Tile(T value, Coordinate co, bool isEmpty) : value(value), co(co), isEmpty(isEmpty){}
    Coordinate getCoordinate();
};

template <typename T> 
class Board;
template<typename T>
class Brain{
public:
    Brain()=delete;
    static std::vector<Direction>getPossibleDirections(const Board<T>* board);
    static bool isMovePossible(const Board<T>* board, const Direction d);
};

template<typename T>
std::ostream& operator<< (std::ostream& out, const Board<T>* board);

template<typename T> 
class Board {
private:
    std::vector<std::vector<Tile<T>>>tiles;
    Tile<T>* empty_tile;
    int n;
public:
  //  Board(int n)=default;
    Board()=default;
    Board(int n, std::vector<std::vector<Tile<T>>>initial);
    ~Board()=default;
    Tile<T> getTile(int i, int j);
    friend bool Brain<T>::isMovePossible(const Board<T> * board, const Direction d);
    void print();
    void makeMove(Direction d);
    
   
    friend vector<Direction> Brain<T>::getPossibleDirections(const Board<T>* Board);
};
#endif