//
// Created by robbie on 11-12-2016.
//

#include "line.h"

line::line(sf::Vector2f vec, sf::Color clr, sf::Vector2f endPos):  position(vec), color(clr), endPosition(endPos) {
    lineShape[0] = sf::Vertex(position, color);
    lineShape[1] = sf::Vertex(endPosition, color);

    rect.left = int(position.x);
    rect.top = int(position.y);
    rect.width = int(endPos.x);
    rect.height = int(endPos.y);
}

sf::Vector2f line::getPosition() const{
    return lineShape[0].position;
}

sf::Vector2f line::getSize() const {
    return lineShape[1].position;
}

std::string line::getType() const{
    return "LINE";
}

sf::Color line::getColor() const{
    return color;
}

void line::update(sf::Event event) {

    if(sf::Mouse::isButtonPressed(sf::Mouse::Left) && rect.contains(event.mouseMove.x, event.mouseMove.y)) {

        lineShape[1].position.x = event.mouseMove.x + (lineShape[1].position.x - lineShape[0].position.x) - 10;
        lineShape[1].position.y = event.mouseMove.y + (lineShape[1].position.y - lineShape[0].position.y) - 10;
        lineShape[0].position.x = event.mouseMove.x - 10;
        lineShape[0].position.y = event.mouseMove.y - 10;

        rect.left = int(lineShape[0].position.x);
        rect.top = int(lineShape[0].position.y);
        rect.width = int(lineShape[1].position.x);
        rect.height = int(lineShape[1].position.y);
    }

}

void line::draw(sf::RenderWindow &window) const {
    window.draw(lineShape, 2, sf::Lines);

}