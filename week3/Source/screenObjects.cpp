//
// Created by robbie on 11-12-2016.
//

#include "screenObjects.h"

screenObjects::screenObjects() {

}

void screenObjects::add(screenObject *scrObj) {
    screenObjects::scrObjVector.push_back(scrObj);
}

std::vector<screenObject*> screenObjects::getScreenObjects() {
    return screenObjects::scrObjVector;
}