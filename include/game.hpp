#pragma once

enum State {on, loose, won};

class Game
{
public:
    unsigned getNumberOfLifes();
    void setNumberOfLifes(unsigned input);
    State setState();
    
    Game():numberOfLifes(5),gameState(on){};

private:
    unsigned numberOfLifes;
    State gameState;
};