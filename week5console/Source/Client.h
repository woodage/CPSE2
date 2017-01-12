//
// Created by robbie on 21-12-2016.
//

#ifndef SKILLED_EAGLE_GAME_CLIENT_H
#define SKILLED_EAGLE_GAME_CLIENT_H

#include <Vector>
#include "ICommand.h"
#include "PlayerSetCommand.h"

class Client {
private:
    Game game;
    ICommand *command;
    std::vector<ICommand*> commands;
public:
    Client(Game &game);
    void update();
};


#endif //SKILLED_EAGLE_GAME_CLIENT_H
