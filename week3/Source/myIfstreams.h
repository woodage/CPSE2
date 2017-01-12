//
// Created by robbie on 14-12-2016.
//

#ifndef SKILLED_EAGLE_GAME_IFSTREAMSSFML_H
#define SKILLED_EAGLE_GAME_IFSTREAMSSFML_H

#include <fstream>
#include <SFML/Graphics.hpp>

std::ifstream & operator>>( std::ifstream & input, sf::Color & rhs ){
    std::string s;
    input >> s;
    const struct { const char * name; sf::Color color; } colors[]{
            { "YELLOW", sf::Color::Yellow },
            { "RED",    sf::Color::Red },
            { "BLACK",    sf::Color::Black },
            { "MAGENTA",    sf::Color::Magenta },
            { "GREEN",    sf::Color::Green },
            { "BLUE",    sf::Color::Blue },
    };

    for( auto const & color : colors ){
        if( color.name == s ){
            rhs = color.color;
            return input;
        }
    }
    if( s == "" ){
        throw end_of_file();
    }
    throw unknown_color( s );
}

std::ofstream & operator<<( std::ofstream & input, const sf::Color rhs ){

    const struct { const char * name; sf::Color color; } colors[]{
            { "YELLOW", sf::Color::Yellow },
            { "RED",    sf::Color::Red },
            { "BLACK",    sf::Color::Black },
            { "MAGENTA",    sf::Color::Magenta },
            { "GREEN",    sf::Color::Green },
            { "BLUE",    sf::Color::Blue },
    };

    for( auto const & color : colors ){
        if( color.color.toInteger() == rhs.toInteger() ) {
            input << color.name;
            return input;
        }
    }
}

std::ifstream & operator>>( std::ifstream & input, sf::Vector2f & rhs ){

    char c;

    if( ! ( input >> c )){ throw end_of_file(); }

    if( c != '(' ){ throw invalid_position( c ); }

    if( ! ( input >> rhs.x )){
        throw char_not_completable(c);
    }

    if( ! ( input >> c )){
        throw char_not_completable(c);
    }

    if( ! ( input >> rhs.y )){
        throw char_not_completable(c);
    }

    if( ! ( input >> c )){
        throw char_not_completable(c);
    }

    if( c != ')' ){ throw invalid_position( c ); }

    return input;
}

#endif //SKILLED_EAGLE_GAME_IFSTREAMSSFML_H
