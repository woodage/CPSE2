#include <iostream>
#include <SFML/Graphics.hpp>
#include "screenObjects.h"
#include "myExceptions.h"
#include "myIfstreams.h"
#include "action.h"

screenObject * screen_object_read( std::ifstream & input ){
    sf::Vector2f position;
    std::string name;

    input >> name;

    input >> position;

    if( name == "CIRCLE" ){

        sf::Color color;
        float size;

        input >> color;
        input >> size;

        return new circle(position, size, color);

    } else if( name == "RECTANGLE" ){
        sf::Color color;
        sf::Vector2f size;

        input >> color;
        input >> size;
        return new rectangle(position, color, size);

    } else if( name == "PICTURE" ){
        std::string path = "Content/sprites/";
        std::string filePath;
        input >> filePath;
        path = path + filePath;

        if (FILE *file = fopen(path.c_str(), "r")) {
            fclose(file);
            return new picture( position, filePath.c_str());
        }

    } else if ( name == "LINE"){
        sf::Color color;
        input >> color;
        sf::Vector2f endPosition;
        input >> endPosition;

        return new line(position, color, endPosition);
    }else if( name == "" ){
        throw end_of_file();
    }

    throw unknown_shape( name.c_str() );
}

void overWriteFile(screenObjects &scrObj) {

    // open the txt file to overwrite
    std::ofstream ofs ("Source/objects.txt", std::ios::out | std::ios::trunc); // clear contents

    // get objects from container
    auto objects = scrObj.getScreenObjects();

    // loop each object
    for(auto const &object: objects) {

        //write object type to file
        ofs << object->getType() << " ";

        // write location to file
        ofs << "(" << object->getPosition().x << "," << object->getPosition().y << ") ";


        // write properties of type to file
        if(object->getType() == "RECTANGLE") {
            ofs << object->getColor()<< " ";
            ofs << "(" << object->getSize().x << "," << object->getSize().y << ") ";
        }

        // write properties of type to file
        if(object->getType() == "CIRCLE") {
            ofs << object->getColor() << " ";
            ofs << object->getRadius() << " ";
        }

        // write properties of type to file
        if(object->getType() == "LINE") {
            ofs << object->getColor() << " ";
            ofs << "(" << object->getSize().x << "," << object->getSize().y << ") ";
        }

        // write properties of type to file
        if(object->getType() == "PICTURE") {
            ofs << object->getImagePath() << " ";
        }


        ofs << "\n";
    }

    ofs.close ();

}

int main( int argc, char *argv[] ){

    // create window
    sf::RenderWindow window{ sf::VideoMode{ 640, 480 }, "SFML window" };

    // create container
    screenObjects screenObjectContainer;

    // open text file
    std::ifstream input("Source/objects.txt");

    try {

        for(;;) {
            // add each screenObject to container class
            screenObjectContainer.add(screen_object_read(input));
        }

    } catch (end_of_file eof) {

        // end of file
        std::cout << eof.what();
    } catch ( std::exception & problem ){

        // problem in file
        std::cout << problem.what();
    }

    // get all objects from container
    auto objects = screenObjectContainer.getScreenObjects();

    // close the input file
    input.close();

    while (window.isOpen()) {

        sf::Event event;
        if( window.pollEvent(event) ){
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }

        window.clear(sf::Color::Black);

        // draw each object
        for(auto const& object: objects) {
            object->update(event);
            object->draw(window);
        }

        window.display();

        sf::sleep(sf::milliseconds(20));

    }

    overWriteFile(screenObjectContainer);

    std::cout << "Terminating application\n";

    return 0;
}