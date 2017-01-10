//
// Created by robbie on 21-12-2016.
//

#include "ClickCommand.h"

ClickCommand::ClickCommand(Game &g, Tile &t): game(g), tile(t) {

}

void ClickCommand::execute(){
    tile.setSymbol(game.getIsPlayerOne() ? 'x' : 'o');
    game.draw();
    game.setIsPlayerOne(!game.getIsPlayerOne());
}

void ClickCommand::undo(){
    tile.setSymbol('.');
    game.setIsPlayerOne(!game.getIsPlayerOne());
    game.draw();

}