//
// Created by robbie on 11-12-2016.
//

#include "picture.h"
#include <iostream>

picture::picture(sf::Vector2f vec, const char *s): position(vec), imagePath(s) {

    std::string path = "Content/sprites/";
    path = path + s;
    if(texture.loadFromFile(path)) {
        sprite.setTexture(texture);
        sprite.setPosition(vec);
    }

    rect.left = int(position.x);
    rect.top = int(position.y);
    rect.width = texture.getSize().x;
    rect.height = texture.getSize().y;

}

std::string picture::getImagePath() const {
    return imagePath;
}

sf::Vector2f picture::getPosition() const{
    return sprite.getPosition();
}

std::string picture::getType() const {
    return "PICTURE";
}

void picture::update(sf::Event event) {

    if(sf::Mouse::isButtonPressed(sf::Mouse::Left) && rect.contains(event.mouseMove.x, event.mouseMove.y)) {
        position = sf::Vector2f(float(event.mouseMove.x) - (rect.width / 2), float(event.mouseMove.y) - (rect.height /2));
        sprite.setPosition(position);
        rect.left = int(position.x);
        rect.top = int(position.y);
    }

}

void picture::draw(sf::RenderWindow &window) const {
    window.draw(sprite);
}