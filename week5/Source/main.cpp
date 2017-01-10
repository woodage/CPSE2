#include <iostream>
#include <SFML/Graphics.hpp>
#include "Game.h"
#include "Client.h"

int main( int argc, char *argv[] ){

    sf::RenderWindow window{ sf::VideoMode{ 640, 480 }, "TIC TAC TOE"};

    // create Game instance
    Game tictactoe(window);

    // create Client
    Client client(tictactoe);

    while (window.isOpen()) {

        sf::Event event;

        if( window.pollEvent(event) ){
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }

        // update client actions
        client.update();

        sf::sleep(sf::milliseconds(50));

    }

    std::cout << "Terminating application\n";
    return 0;
}

