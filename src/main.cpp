#include <iostream> 
using namespace std; 
#include "Board.cpp"
#include <error.h>
#include "Coordinate.cpp"
#include "Direction.h"
#include "GameManager.cpp"
#include "BoardInitializer.cpp"
int main(){
    vector <vector<Tile<int>>> tiles; 
    
    Board<int>board = BoardInitializer::initialize_board<int>(4, 10);
    while(true) {
        GameManager<int>gm(&board);
        gm.printBoard();
        gm.showAvailableMoves();
        char c; cin >> c;
        try {
            Direction d = fromChar(c);
            
            bool x = gm.makeMove(d);
            if(!x) throw std::runtime_error("illegal move");
        }
        catch(const std::exception e) {
            cout << "Illegal Move!\n";
        }

    }
}