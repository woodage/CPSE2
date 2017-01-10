//
// Created by robbie on 14-12-2016.
//

#ifndef SKILLED_EAGLE_GAME_ACTION_H
#define SKILLED_EAGLE_GAME_ACTION_H

#include <SFML/Graphics.hpp>
#include <functional>

class action {

private:
    std::function<bool()> condition;
    std::function<void()> work;
public:
    action(
        sf::Mouse::Button button,
        std::function<void()> work
    ): condition([button]()->bool { return sf::Mouse::isButtonPressed(button); }),
       work(work) {

    }

    void operator()() {
        if(condition()) {
            work();
        }
    }

};


#endif //SKILLED_EAGLE_GAME_ACTION_H
