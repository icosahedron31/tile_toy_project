#ifndef BOARDINITIAL_H
#define BOARDINITIAL_H 
#include <vector>
#include "Coordinate.h"
namespace BoardInitializer{
    template<typename T>
    Board<T> initialize_board(int n, int moves);
};

#endif 