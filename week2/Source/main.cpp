//
// Created by robbie on 11/30/2016.
//

#include <SFML/Graphics.hpp>
#include "ball.h"
#include "wall.h"
#include "block.h"
#include "action.h"

int main()
{
    // make instance of window
    sf::RenderWindow window(sf::VideoMode(640, 480), "Week 2!");

    // creating ball instance
    Ball ball(sf::Vector2f(250.f,360.f), window, sf::Vector2f(5.f, -2.f));

    // creating the walls
    Wall wall_top(sf::Vector2f(0.f, 0.f), window.getSize().x, 20.f, window);
    Wall wall_bottom(sf::Vector2f(0.f, window.getSize().y - 20), window.getSize().x, 20.f, window);
    Wall wall_left(sf::Vector2f(0.f, 0.f), 20.f, window.getSize().y, window);
    Wall wall_right(sf::Vector2f(window.getSize().x, 0.f), -20.f, window.getSize().y, window);

    // creating a block
    Block block(sf::Vector2f(100.f, 130.f), window);

    // define actions in game
    Action actions[] = {

        // moving block with keyboard
        Action(sf::Keyboard::Up, [&]{ block.moveUp(); }),
        Action(sf::Keyboard::Down, [&]{ block.moveDown(); }),
        Action(sf::Keyboard::Left, [&]{ block.moveLeft(); }),
        Action(sf::Keyboard::Right, [&]{ block.moveRight(); }),

        // ball interaction with walls
        Action(wall_bottom.getRectangle(), ball.getRectangle(), [&] { ball.flipY(); }),
        Action(wall_top.getRectangle(), ball.getRectangle(), [&] { ball.flipY(); }),
        Action(wall_right.getRectangle(), ball.getRectangle(), [&] { ball.flipX(); }),
        Action(wall_left.getRectangle(), ball.getRectangle(), [&] { ball.flipX(); }),

        // ball interaction with block
        Action( [&]{ ball.handleCollisionWithBlock(block); }),

        // ball move
        Action( [&]{ ball.move(); }),
    };

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear(sf::Color::White);

        // update all defined actions
        for(auto &action : actions) {
            action();
        }

        while(sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {

        }

        // draw
        ball.draw();
        wall_top.draw();
        wall_bottom.draw();
        wall_left.draw();
        wall_right.draw();
        block.draw();

        window.display();
        sf::sleep(sf::milliseconds(20));
    }

    return 0;
}