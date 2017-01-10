//
// Created by robbie on 8-12-2016.
//

#ifndef SKILLED_EAGLE_GAME_WALL_H
#define SKILLED_EAGLE_GAME_WALL_H

#include <SFML/Graphics.hpp>
#include "screenObject.h"

class Wall : public ScreenObject {
private:
    sf::RectangleShape shape;
    sf::RenderWindow &window;
    sf::IntRect rect;
public:

    Wall(sf::Vector2f vec2f, float width, float height, sf::RenderWindow &w): window(w), rect(sf::IntRect(vec2f.x, vec2f.y, width, height)), shape(sf::RectangleShape()) {
        shape.setSize(sf::Vector2f(width, height));
        shape.setPosition(vec2f);
        shape.setFillColor(sf::Color::Black);
    };

    sf::IntRect &getRectangle() {
        return rect;
    }

    virtual void draw() {
        window.draw(shape);
    }
};


#endif //SKILLED_EAGLE_GAME_WALL_H
