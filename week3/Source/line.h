//
// Created by robbie on 11-12-2016.
//

#ifndef SKILLED_EAGLE_GAME_LINE_H
#define SKILLED_EAGLE_GAME_LINE_H

#include "screenObject.h"
#include <SFML/Graphics.hpp>

class line : public screenObject {
public:
    line(sf::Vector2f vec, sf::Color clr, sf::Vector2f endPos);
    sf::Vector2f getPosition() const;
    std::string getType() const;
    sf::Vector2f getSize() const;
    sf::Color getColor() const;
    void update(sf::Event event);
    void draw( sf::RenderWindow & window ) const;
private:
    sf::Vector2f position;
    sf::Color color;
    sf::Vector2f endPosition;
    sf::Vertex lineShape[2];
    sf::IntRect rect;
};


#endif //SKILLED_EAGLE_GAME_LINE_H
