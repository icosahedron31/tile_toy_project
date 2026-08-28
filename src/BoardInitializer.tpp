#include <vector> 
#include "BoardInitializer.h"
#include "Board.h"
template <typename T> 
Board<T> BoardInitializer::initialize_board(int n, int moves) {
    std::vector <std::vector<Tile<int>>> tiles; 
        tiles.resize(n);
        
        for(int i = 0; i < n; i++) {
            tiles[i].resize(n);
            for(int j = 0; j < n; j++) {
                Coordinate x = {i, j, n};
                tiles[i][j] = {i * n + j, x, (i == 0 && j == 0)};
            }
        }
        Board<int>board{n, tiles};
        for(int i = 0; i < moves; i++) {
            std::vector<Direction> possible_moves = Brain<T>::getPossibleDirections(&board);
            int x = rand() % static_cast<int>(possible_moves.size());
            board.makeMove(possible_moves[x]);
        }
        return board;
}