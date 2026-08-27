#ifndef GAME_H 
#define GAME_H 
#include "Board.h"


template <typename T> 
class Game {
private: 
    Board<T> board; 
    GameManager<T> gameManager;
public:
    Game();
    ~Game();
    void play();
};

#endif 