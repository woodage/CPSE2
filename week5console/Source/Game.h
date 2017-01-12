//
// Created by robbie on 21-12-2016.
//

#ifndef SKILLED_EAGLE_GAME_GAME_H
#define SKILLED_EAGLE_GAME_GAME_H

#include <SFML/Graphics.hpp>
#include <Vector>
#include <iostream>
#include <algorithm>

#include "Tile.h"

class Game {

private:
    /*
     * Boolean true represent player one. Player one will be a cross in the game.
     * Player two will represented as circle.
     */
    bool isPlayerOne;

    // window object
    sf::RenderWindow &window;

    // tiles representive for GUI
    std::vector<Tile> tiles;

public:

    Game(sf::RenderWindow &w);
    bool getIsPlayerOne();
    void setIsPlayerOne(bool playerOne);
    void initField();
    bool isWinner();
    void displayInConsole();
    std::vector<Tile> &getTiles();
    void draw();

};


#endif //SKILLED_EAGLE_GAME_GAME_H
