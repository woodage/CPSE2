//
// Created by robbie on 21-12-2016.
//

#include "Client.h"

Client::Client(Game &game): game(game) {
}

void Client::update() {

    if(!game.isWinner()) {
        if (sf::Mouse().isButtonPressed(sf::Mouse::Left)) {
            for (auto &tile : game.getTiles()) {
                if (tile.isClicked() && !tile.isUsed()) {
                    command = new ClickCommand(game, tile);
                    command->execute();
                    commands.push_back(command);
                }
            }
        }
    }

    if(sf::Mouse().isButtonPressed(sf::Mouse::Right)) {
        if(!commands.empty()) {
            commands.back()->undo();
            commands.pop_back();
        }
    }

}