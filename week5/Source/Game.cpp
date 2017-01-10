//
// Created by robbie on 21-12-2016.
//

#include "Game.h"

Game::Game(sf::RenderWindow &w): window(w) {
    initField();
    draw();
}

bool Game::getIsPlayerOne() {
    return isPlayerOne;
}

void Game::setIsPlayerOne(bool playerOne) {
    isPlayerOne = playerOne;
}

void Game::initField() {

    int id = 1;

    for(int i = 0; i < 3; i++) {

        for(int j = 0; j < 3; j++) {

            // calculate positions for each tile
            Tile t(id, sf::Vector2f(float((j * 100)  + 150), float((i * 100) + 50)), window);
            tiles.push_back(t);

            id++;
        }
    }

}

std::vector<Tile> &Game::getTiles() {
    return tiles;
}

bool Game::isWinner() {
    char s = isPlayerOne ? 'o' : 'x';

    // vertical
    if(tiles[0].getSymbol() == s && tiles[1].getSymbol() == s && tiles[2].getSymbol() == s) {
        return true;
    }

    if(tiles[3].getSymbol() == s && tiles[4].getSymbol() == s && tiles[5].getSymbol() == s) {

        return true;
    }

    if(tiles[6].getSymbol() == s && tiles[7].getSymbol() == s && tiles[8].getSymbol() == s) {
        std::cout<< 6 << 7 << 8;
        return true;
    }

    // horizontal
    if(tiles[0].getSymbol() == s && tiles[3].getSymbol() == s && tiles[6].getSymbol() == s) {
        return true;
    }

    if(tiles[1].getSymbol() == s && tiles[4].getSymbol() == s && tiles[7].getSymbol() == s) {
        return true;
    }

    if(tiles[2].getSymbol() == s && tiles[5].getSymbol() == s && tiles[8].getSymbol() == s) {
        return true;
    }

    // diagonal
    if(tiles[0].getSymbol() == s && tiles[4].getSymbol() == s && tiles[8].getSymbol() == s) {
        return true;
    }

    if(tiles[2].getSymbol() == s && tiles[4].getSymbol() == s && tiles[6].getSymbol() == s) {
        return true;
    }

    return  false;
}

void Game::displayInConsole() {

    int x = 0;

    for(int i = 0; i < 3; i++) {

        for(int j = 0; j < 3; j++) {

            // calculate positions for each tile
            std::cout << tiles[x].getSymbol() << " ";
            x++;
        }

        std::cout << "\n";
    }

    std::cout << "----- \n";
}

void Game::draw() {

    displayInConsole();

    // only the Game object can clear and display screen
    window.clear(sf::Color::White);

    // loop each object inside game
    for(auto &tile : tiles) {

        tile.draw();
    }

    // display to screen
    window.display();
}