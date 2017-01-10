//
// Created by robbie on 21-12-2016.
//

#ifndef SKILLED_EAGLE_GAME_TILE_H
#define SKILLED_EAGLE_GAME_TILE_H
#include <SFML/Graphics.hpp>

class Tile {
    private:
        int id;
        sf::RectangleShape shape;
        sf::IntRect rect;
        sf::RenderWindow &window;
        char symbol;
    public:
        Tile(int id, sf::Vector2f, sf::RenderWindow &w);
        ~Tile();
        int getId() const;
        char getSymbol() const;
        void setSymbol(char c);
        bool isClicked() const;
        bool isUsed() const;
        void draw() const;
};


#endif //SKILLED_EAGLE_GAME_TILE_H
