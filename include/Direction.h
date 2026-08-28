#include <stdexcept>
#ifndef DIRECTION_H 
#define DIRECTION_H
enum Direction{
    W = 'W', 
    E = 'E', 
    S = 'S', 
    N = 'N',
};


Direction operator-(const Direction& dir) {
    switch(dir) {
        case Direction::W: return Direction::E; 
        case Direction::E: return Direction::W;
        case Direction::S: return Direction::N;
        case Direction::N: return Direction::S;
    }
    throw std::invalid_argument("Invalid Direction");
}

Direction fromChar(char c) {
    switch (c) {
        case 'N': return Direction::N;
        case 'E': return Direction::E;
        case 'S': return Direction::S;
        case 'W': return Direction::W;
        default:
            throw std::invalid_argument("Invalid direction");
    }
}

#endif
