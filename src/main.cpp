#include <iostream> 
using namespace std; 
#include "Board.cpp"
#include <error.h>
#include "Coordinate.cpp"
#include "Direction.h"
#include "GameManager.cpp"
int main(){
    vector <vector<Tile<int>>> tiles; 
    tiles.resize(4);
    for(int i = 0; i < 4; i++) {
        tiles[i].resize(4);
        for(int j = 0; j < 4; j++) {
            Coordinate x = {i, j, 4};
            tiles[i][j] = {i * 4 + j, x, (i == 0 && j == 0)};
        }
    }
    Board<int>board{4, tiles};
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