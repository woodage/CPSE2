//
// Created by robbie on 21-12-2016.
//

#include "Tile.h"
#include <iostream>

Tile::Tile(int id, sf::Vector2f vec2f, sf::RenderWindow &w): id(id), window(w) {

    // shape
    shape.setPosition(vec2f);
    shape.setSize(sf::Vector2f(100,100));
    shape.setOutlineColor(sf::Color::Red);
    shape.setOutlineThickness(1.f);

    // rectangle
    rect.left = vec2f.x;
    rect.top = vec2f.y;
    rect.width = 100;
    rect.height = 100;

    symbol = '.';
}

Tile::~Tile() {

}

bool Tile::isClicked() const {
    return rect.contains(sf::Mouse::getPosition(window)) && sf::Mouse::isButtonPressed(sf::Mouse::Left);
}

int Tile::getId() const {
    return id;
}

char Tile::getSymbol() const {
    return symbol;
}

void Tile::setSymbol(char c) {
    symbol = c;
}

bool Tile::isUsed() const {
       return symbol == 'x' || symbol == 'o';
}

void Tile::draw() const {
    window.draw(shape);
    if(symbol == 'x') {
        sf::Vertex line[] = {
            sf::Vertex(sf::Vector2f(shape.getPosition().x + 10, shape.getPosition().y + 10), sf::Color::Red),
            sf::Vertex(sf::Vector2f(shape.getPosition().x + 90,shape.getPosition().y + 90), sf::Color::Red)
        };
        sf::Vertex line1[] = {
                sf::Vertex(sf::Vector2f(shape.getPosition().x + 10, shape.getPosition().y + 90), sf::Color::Red),
                sf::Vertex(sf::Vector2f(shape.getPosition().x + 90,shape.getPosition().y + 10), sf::Color::Red)
        };
        window.draw(line, 2, sf::Lines);
        window.draw(line1, 2, sf::Lines);

    }
    if(symbol == 'o') {
        sf::CircleShape circle(40.f);
        circle.setOutlineColor(sf::Color::Red);
        circle.setOutlineThickness(1.f);
        circle.setPosition(sf::Vector2f(shape.getPosition().x + 10, shape.getPosition().y + 10));
        window.draw(circle);
    }
}