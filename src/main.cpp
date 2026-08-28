#include <iostream> 
using namespace std; 
#include "Board.h"
#include <error.h>
#include "Coordinate.h"
#include "Direction.h"
#include "GameManager.h"
#include "BoardInitializer.h"
#include "Game.h"
int main(){
    vector <vector<Tile<int>>> tiles; 
    
    Board<int>board = BoardInitializer::initialize_board<int>(4, 10);
    Game<int> game = {};
    game.play();
}