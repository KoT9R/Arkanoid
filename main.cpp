#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include "Engine.h"

int main() {

// Create the main window
    sf::Clock clock;
    sf::RenderWindow window(sf::VideoMode(Constants::WindowSizeX, Constants::WindowSizeY), "Arkanoid");


    Racket padle(&window);
    Ball myball(&window);
    //Block myBlock(&window,sf::Vector2f(960, 516));
    std::vector <std::vector <Block>> blocks;
    CreateBlocks(Constants::BlockX, Constants::BlockY, blocks, &window);

    while (window.isOpen()){
        sf::Event event;
        float time = clock.getElapsedTime().asMicroseconds();
        clock.restart();
        time = time /  1600;
        while(window.pollEvent(event)){
            if (event.type == sf::Event::Closed ||
                    (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape))
                window.close();
        }
        CollisionRacketBall(padle,myball);
        //CollisionBallBlock(myball,myBlock);
        DeleteBlocks(blocks,myball);
        myball.update(time);
        padle.update(time);
        window.clear();
        //myBlock.draw();
        DrawBlocks(Constants::BlockX, Constants::BlockY, blocks);
        myball.draw();
        padle.draw();
        window.display();

    }

    return EXIT_SUCCESS;
}