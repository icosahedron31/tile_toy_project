#include <iostream> 
using namespace std; 
#include "Board.cpp"
#include <error.h>
#include "Coordinate.cpp"
#include "Direction.h"
#include "GameManager.cpp"
#include "BoardInitializer.cpp"
#include "Game.cpp"
int main(){
    vector <vector<Tile<int>>> tiles; 
    
    Board<int>board = BoardInitializer::initialize_board<int>(4, 10);
    Game<int> game = {};
    game.play();
}