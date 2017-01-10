//
// Created by robbie on 8-12-2016.
//

#ifndef SKILLED_EAGLE_GAME_BALL_H
#define SKILLED_EAGLE_GAME_BALL_H

#include <SFML/Graphics.hpp>

#include "screenObject.h"
#include "block.h"

class Ball : public ScreenObject{

private:

    sf::Vector2f vec2f;
    sf::CircleShape shape;
    sf::RenderWindow &window;
    sf::IntRect rect;
    sf::Vector2f moveDirection;

public:

    Ball(sf::Vector2f v, sf::RenderWindow &w, sf::Vector2f moveDir): vec2f(v), shape(sf::CircleShape(20.f)), window(w), rect(sf::IntRect(int(vec2f.x), int(vec2f.y), 20, 20 )), moveDirection(moveDir) {
        shape.setPosition(vec2f);
        shape.setFillColor(sf::Color::Blue);

    };

    sf::IntRect &getRectangle() {
        return rect;
    }

    void setMoveDirection(sf::Vector2f newMoveDirection){
        moveDirection = newMoveDirection;
    }

    void handleCollisionWithBlock(Block &block) {

        int border = 1;

        // create a new rectangles based on block rectangle to check if intersection is true.
        sf::IntRect leftRect = sf::IntRect(block.getRectangle().left - (border + 20), block.getRectangle().top, border, block.getRectangle().height);
        sf::IntRect rightRect = sf::IntRect(block.getRectangle().left + block.getRectangle().width - 20, block.getRectangle().top, border, block.getRectangle().height);
        sf::IntRect topRect = sf::IntRect(block.getRectangle().left, block.getRectangle().top, block.getRectangle().width, border);
        sf::IntRect bottomRect = sf::IntRect(block.getRectangle().left + block.getRectangle().height, block.getRectangle().top, block.getRectangle().width, border);

        // ball intersects left side of block
        if(rect.intersects(leftRect)) {
            moveDirection = sf::Vector2f(-5.0f, 2.0f);
        }

        // ball intersects right side of block
        if(rect.intersects(rightRect)) {
            moveDirection = sf::Vector2f(5.0f, -2.0f);
        }

        // ball intersects top side of block
        if(rect.intersects(topRect)) {
            moveDirection = sf::Vector2f(-5.0f, -2.0f);
        }

        // ball intersects bottom side of block
        if(rect.intersects(bottomRect)) {
            moveDirection = sf::Vector2f(5.0f, 2.0f);
        }

    }

    void move() {
        shape.move(moveDirection);
        rect = sf::IntRect(shape.getPosition().x, shape.getPosition().y, 20, 20);
    }

    void draw() {
        window.draw(shape);
    }



};


#endif //SKILLED_EAGLE_GAME_BALL_H
