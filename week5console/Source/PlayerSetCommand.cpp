//
// Created by robbie on 21-12-2016.
//

#include "PlayerSetCommand.h"

PlayerSetCommand::PlayerSetCommand(Game &g, Tile &t): game(g), tile(t) {

}

void PlayerSetCommand::execute(){
    tile.setSymbol(game.getIsPlayerOne() ? 'x' : 'o');
    game.draw();
    game.setIsPlayerOne(!game.getIsPlayerOne());
}

void PlayerSetCommand::undo(){
    tile.setSymbol('.');
    game.setIsPlayerOne(!game.getIsPlayerOne());
    game.draw();
}