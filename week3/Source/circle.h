#ifndef _BALL_HPP
#define _BALL_HPP

#include <SFML/Graphics.hpp>
#include "screenObject.h"
class circle: public screenObject {
public:

    circle( sf::Vector2f position, float size, sf::Color color );
    sf::Vector2f getPosition() const;
    std::string getType() const;
    sf::Color getColor() const;
    float getRadius()  const;
    void update(sf::Event event);
    void draw( sf::RenderWindow & window ) const;

private:
    sf::Vector2f position;
    float size;
    sf::Color color;
    sf::CircleShape shape;
    sf::IntRect rect;
};

#endif
