#include "GameManager.h"
#include <iostream>

template<typename T>
GameManager<T>::GameManager(Board<T>* board) : board(board), move_count(0){
    
}

template<typename T>
void GameManager<T>::showAvailableMoves() {
    std::vector<Direction> d = Brain<T>::getPossibleDirections(board);
    cout << "Available Moves: ";
    for(const auto & to : d) {
        cout << static_cast<char>(to) << ' ';
    }
    cout << '\n';
}
template <typename T> 
void GameManager<T>::printBoard() {
    board->print();
}


template <typename T> 
bool GameManager<T>::makeMove(Direction d) {
    if(!Brain<T>::isMovePossible(board, d)) {
        return false;
    }
    board->makeMove(d);
    return true;
}



