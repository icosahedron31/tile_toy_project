#include "Game.h"
#include "BoardInitializer.h"

template<typename T>
Game<T>::Game() {
    board = std::move(BoardInitializer::initialize_board<T>(4, 100));
    gameManager = {&board};
}

template<typename T>
Game<T>::~Game(){}


template<typename T>
void  Game<T>::play(){
    while(true) {
        gameManager.printBoard();
        gameManager.showAvailableMoves();
        char c; cin >> c;
        if(c == 'Q') break;
        try {
            Direction d = fromChar(c);
            
            bool x = gameManager.makeMove(d);
            if(!x) throw std::runtime_error("illegal move");
        }
        catch(const std::exception e) {
            cout << "Illegal Move!\n";
        }
    }
}