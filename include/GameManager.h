#ifndef GAMEMANAGER_H 
#define GAMEMANAGER_H
#include "Board.h"

template<typename T> 
class GameManager{
private:
    Board <T>* board; 
    int move_count;
public:
    GameManager()=default; 
    GameManager(Board<T>* board);
    void printBoard();
    void showAvailableMoves();
    int getNumberOfMoves();
    bool makeMove(Direction d);

};
#include "../src/GameManager.tpp"
#endif 

