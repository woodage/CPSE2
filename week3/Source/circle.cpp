#include <SFML/Graphics.hpp>
#include "circle.h"

circle::circle(sf::Vector2f position, float size, sf::Color color ) :
        position{ position },
        size{ size },
        color{ color }
{

    shape.setRadius(size);
    shape.setPosition(position);
    shape.setFillColor(color);
    rect.left = int(position.x);
    rect.top = int(position.y);
    rect.height = 2 * int(size);
    rect.width = 2 * int(size);
}

std::string circle::getType() const {
    return "CIRCLE";
}

sf::Color circle::getColor() const {
    return color;
}

float circle::getRadius() const {
    return size;
}

sf::Vector2f circle::getPosition() const{
    return shape.getPosition();
}


void circle::update(sf::Event event) {

    if(sf::Mouse::isButtonPressed(sf::Mouse::Left) && rect.contains(event.mouseMove.x, event.mouseMove.y)) {

        shape.setPosition(float(event.mouseMove.x) - (rect.width / 2),
                          float(event.mouseMove.y) - (rect.height / 2));
        rect.left = int(shape.getPosition().x);
        rect.top = int(shape.getPosition().y);
        rect.height = 2 * int(size);
        rect.width = 2 * int(size);
    }
}


void circle::draw( sf::RenderWindow & window ) const {

    window.draw(shape);
}

