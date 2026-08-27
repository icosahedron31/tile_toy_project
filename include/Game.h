#ifndef GAME_H 
#define GAME_H 


enum Command{
    Q = 'Q', 
    E = 'E', 
    W = 'W', 
    S = 'S', 
    N = 'N'
};

template <typename T> 
class Game {
private: 
    Board<T> board; 
    GameManager<T> gameManager;
public:
    Game();
    ~Game();
    void play();
    Command getCommand();
    
};

#endif 