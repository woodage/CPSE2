//
// Created by robbie on 11-12-2016.
//

#include "rectangle.h"
#include <iostream>

rectangle::rectangle(sf::Vector2f vec, sf::Color clr, sf::Vector2f size): position(vec), color(clr) {
    shape.setPosition(vec);
    shape.setFillColor(color);
    shape.setSize(size);
    rect = sf::IntRect(int(vec.x),int(vec.y), int(size.x), int(size.y));
}

sf::Vector2f rectangle::getPosition() const {
    return shape.getPosition();
}

sf::Vector2f rectangle::getSize() const {
    return shape.getSize();
}

sf::Color rectangle::getColor() const {
    return color;
}

std::string rectangle::getType() const {
    return "RECTANGLE";
}

void rectangle::update(sf::Event event) {

    if(sf::Mouse::isButtonPressed(sf::Mouse::Left) && rect.contains(event.mouseMove.x, event.mouseMove.y)) {

            shape.setPosition(float(event.mouseMove.x) - (rect.width / 2),
                              float(event.mouseMove.y) - (rect.height / 2));
            rect.left = shape.getPosition().x;
            rect.top = shape.getPosition().y;
    }
}

void rectangle::draw(sf::RenderWindow &window) const {
    window.draw(shape);
}