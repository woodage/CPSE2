//
// Created by robbie on 21-12-2016.
//

#ifndef SKILLED_EAGLE_GAME_GAMECOMMAND_H
#define SKILLED_EAGLE_GAME_GAMECOMMAND_H

#include <iostream>

class ICommand {

public:
    virtual void execute() = 0;
    virtual void undo() = 0;
};


#endif //SKILLED_EAGLE_GAME_GAMECOMMAND_H
