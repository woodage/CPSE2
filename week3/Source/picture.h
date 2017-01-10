//
// Created by robbie on 11-12-2016.
//

#ifndef SKILLED_EAGLE_GAME_PICTURE_H
#define SKILLED_EAGLE_GAME_PICTURE_H

#include "screenObject.h"
#include "SFML/Graphics.hpp"

class picture: public screenObject {

private:
    std::string imagePath;
    sf::Vector2f position;
    sf::Sprite sprite;
    sf::Texture texture;
    sf::IntRect rect;

public:
    picture(sf::Vector2f vec, const char *s);
    sf::Vector2f getPosition() const;
    std::string getType() const;
    std::string getImagePath() const;
    void update(sf::Event event);
    void draw( sf::RenderWindow & window ) const;
};


#endif //SKILLED_EAGLE_GAME_PICTURE_H
