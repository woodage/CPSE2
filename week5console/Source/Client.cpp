//
// Created by robbie on 21-12-2016.
//

#include "Client.h"
#include "Client.h"

Client::Client(Game &game): game(game) {
}

void Client::update() {

    if(game.isWinner()) {
        std::cout << "Speler: " << (int(!game.getIsPlayerOne()) + 1) << " heeft gewonnen.";
    }

    char inputConsole;
    std::cin >> inputConsole;

    if(!game.isWinner()) {
        // with mouse interface
        if (inputConsole >= '1' && inputConsole <= '9') {
            for (auto &tile : game.getTiles()) {
                if (tile.getId() == (inputConsole - 48) && !tile.isUsed()) {
                    command = new PlayerSetCommand(game, tile);
                    command->execute();
                    commands.push_back(command);
                }
            }
        }
    }

    if(inputConsole == 'u') {
        if(!commands.empty()) {
            commands.back()->undo();
            commands.pop_back();
        }
    }
}