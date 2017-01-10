//
// Created by robbie on 11-12-2016.
//

#ifndef SKILLED_EAGLE_GAME_SCREENOBJECT_H
#define SKILLED_EAGLE_GAME_SCREENOBJECT_H

#include <SFML/Graphics.hpp>

class screenObject {
public:
    // get position
    virtual sf::Vector2f getPosition() const = 0;

    // get type
    virtual std::string getType() const = 0;

    // get color
    virtual sf::Color getColor() const {}

    // get size vector
    virtual sf::Vector2f getSize() const {}

    // get radius
    virtual float getRadius() const {}

    // get picturePath
    virtual std::string getImagePath() const {}

    // update method
    virtual void update(sf::Event event) = 0;

    // draw method
    virtual void draw( sf::RenderWindow & window ) const = 0;
};


#endif //SKILLED_EAGLE_GAME_SCREENOBJECT_H
