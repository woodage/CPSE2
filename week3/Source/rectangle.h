//
// Created by robbie on 11-12-2016.
//

#ifndef SKILLED_EAGLE_GAME_RECTANGLE_H
#define SKILLED_EAGLE_GAME_RECTANGLE_H

#include "rectangle.h"
#include "screenObject.h"
#include <SFML/Graphics.hpp>

class rectangle : public screenObject {
private:
    sf::Vector2f position;
    sf::Color color;
    sf::RectangleShape shape;
    sf::IntRect rect;

public:
    rectangle(sf::Vector2f vec, sf::Color clr, sf::Vector2f size);
    sf::Vector2f getPosition() const;
    sf::Vector2f getSize() const;
    std::string getType() const;
    sf::Color getColor() const;
    void update(sf::Event event);
    void draw( sf::RenderWindow & window ) const;
};


#endif //SKILLED_EAGLE_GAME_RECTANGLE_H
