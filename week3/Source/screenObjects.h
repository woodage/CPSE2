//
// Created by robbie on 11-12-2016.
//

#ifndef SKILLED_EAGLE_GAME_SCREENOBJECTS_H
#define SKILLED_EAGLE_GAME_SCREENOBJECTS_H


#include <vector>
#include "circle.h"
#include "rectangle.h"
#include "line.h"
#include "picture.h"
#include "screenObject.h"

class screenObjects {
    private:
        std::vector<screenObject*> scrObjVector;

    public:
    screenObjects();
    void add(screenObject* scrObj);

    std::vector<screenObject*> getScreenObjects();
};


#endif //SKILLED_EAGLE_GAME_SCREENOBJECTS_H
