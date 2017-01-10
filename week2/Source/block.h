//
// Created by robbie on 8-12-2016.
//

#ifndef SKILLED_EAGLE_GAME_BLOCK_H
#define SKILLED_EAGLE_GAME_BLOCK_H

#include <SFML/Graphics.hpp>
#include "ScreenObject.h"

class Block : public ScreenObject{
private:

    sf::Vector2f vec2f;
    sf::RectangleShape shape;
    sf::RenderWindow &window;
    sf::IntRect rect;
    float speed;
public:

    Block(sf::Vector2f v, sf::RenderWindow &w): vec2f(v), shape(sf::RectangleShape()), window(w), speed(5.f), rect(int(v.x), int(v.y), 40, 40){
        shape.setSize(sf::Vector2f(40.f, 40.f));
        shape.setPosition(vec2f);
        shape.setFillColor(sf::Color::Red);
    }

    sf::IntRect getRectangle() {
        return rect;
    }

    sf::Vector2f getPosition() {
        return shape.getPosition();
    }

    void setSpeed(float newSpeed) {
        speed = newSpeed;
    }

    void moveUp() {
        shape.move(sf::Vector2f(0.f, -speed));
        rect = sf::IntRect(int(shape.getPosition().x), int(shape.getPosition().y), 40, 40);
    }

    void moveDown() {
        shape.move((sf::Vector2f(0.f, speed)));
        rect = sf::IntRect(int(shape.getPosition().x), int(shape.getPosition().y), 40, 40);
    }

    void moveLeft() {
        shape.move((sf::Vector2f(-speed, 0.f)));
        rect = sf::IntRect(int(shape.getPosition().x), int(shape.getPosition().y), 40, 40);
    }

    void moveRight() {
        shape.move((sf::Vector2f(speed, 0.f)));
        rect = sf::IntRect(int(shape.getPosition().x), int(shape.getPosition().y), 40, 40);
    }

    void draw() {
        window.draw(shape);
    }
};


#endif //SKILLED_EAGLE_GAME_BLOCK_H
