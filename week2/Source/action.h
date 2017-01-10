//
// Created by robbie on 8-12-2016.
//

#ifndef SKILLED_EAGLE_GAME_ACTIONS_H
#define SKILLED_EAGLE_GAME_ACTIONS_H

#include <functional>
#include <SFML/Window/Keyboard.hpp>
#include <SFML/Window/Mouse.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
class Action {
private:
    std::function< bool() > condition;
    std::function< void() > work;

public:

    Action(
            std::function< void() > work
    ) :
            condition([]{ return true; }),
            work(work)
    {}

    Action(
        std::function< bool() > condition,
        std::function< void() > work
    ) :
        condition(condition),
        work(work)
    {}

    Action(
        sf::Keyboard::Key key,
        std::function< void() > work
    ) :
        condition(
            [ key ]()->bool { return sf::Keyboard::isKeyPressed( key ); }
        ),
        work(work)
    {}

    Action(
        sf::Mouse::Button button,
        std::function< void() > work
    ) :
        condition(
            [ button ]()->bool { return sf::Mouse::isButtonPressed( button ); }
        ),
        work(work)
    {}

    Action(
        sf::IntRect &rect,
        sf::IntRect &rect2,
        std::function< void() > work
    ) :
        condition(
            [&]()->bool { return rect.intersects( rect2 ); }
        ),
        work(work)
    {}

    void operator()(){
        if( condition()) {
            work();
        }

    }
};

#endif //SKILLED_EAGLE_GAME_ACTIONS_H