//
// Created by robbie on 21-12-2016.
//

#ifndef SKILLED_EAGLE_GAME_PLACECOMMAND_H
#define SKILLED_EAGLE_GAME_PLACECOMMAND_H

#include "ICommand.h"
#include "Game.h"

class PlayerSetCommand : public ICommand {
private:
    Game &game;
    Tile &tile;

public:
    PlayerSetCommand(Game &game, Tile &tile);
    void execute() override;
    void undo() override;
};


#endif //SKILLED_EAGLE_GAME_PLACECOMMAND_H
