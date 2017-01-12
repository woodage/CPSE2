//
// Created by robbie on 8-12-2016.
//

#ifndef SKILLED_EAGLE_GAME_BLOCK_H
#define SKILLED_EAGLE_GAME_BLOCK_H

#include <SFML/Graphics.hpp>

class Block {
private:
    sf::Vector2f vec2f;
    sf::RectangleShape shape;
    sf::RenderWindow &window;
    sf::IntRect rect;
    float speed;
public:

    Block(sf::Vector2f v, sf::RenderWindow &w): vec2f(v), shape(sf::RectangleShape()), window(w), speed(2.f), rect(int(v.x), int(v.y), 100, 100){
        shape.setSize(sf::Vector2f(100.f, 100.f));
        shape.setPosition(vec2f);
        shape.setFillColor(sf::Color::Red);
    }

    sf::IntRect getRectangle() {
        return rect;
    }

    void moveUp() {
        shape.move(sf::Vector2f(0.f, -speed));
        rect = sf::IntRect(int(shape.getPosition().x), int(shape.getPosition().y), 100, 100);
    }

    void moveDown() {
        shape.move((sf::Vector2f(0.f, speed)));
        rect = sf::IntRect(int(shape.getPosition().x), int(shape.getPosition().y), 100, 100);
    }

    void moveLeft() {
        shape.move((sf::Vector2f(-speed, 0.f)));
        rect = sf::IntRect(int(shape.getPosition().x), int(shape.getPosition().y), 100, 100);
    }

    void moveRight() {
        shape.move((sf::Vector2f(speed, 0.f)));
        rect = sf::IntRect(int(shape.getPosition().x), int(shape.getPosition().y), 100, 100);
    }

    void draw() {
        window.draw(shape);
    }
};


#endif //SKILLED_EAGLE_GAME_BLOCK_H
