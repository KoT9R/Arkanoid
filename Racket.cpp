//
// Created by Denis on 2019-08-04.
//

#include "Racket.h"

Racket::Racket(sf::RenderWindow *window):
        __window(window),__score (0), Rectangle(Constants::WidthRacket, Constants::HeightRacket){
    __rectangle.setSize(sf::Vector2f(__rectangleWidth, __rectangleHeight));
    __rectangle.setOrigin(sf::Vector2f(__rectangleWidth / 2, __rectangleHeight / 2));
    __rectangle.setPosition(sf::Vector2f((float)Constants::WindowSizeX / 2, Constants::WindowSizeY - __rectangleHeight - Constants::HeightforRacket));
}

void Racket::draw() {
    __window->draw(__rectangle);
}

void Racket::update(float time) {
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) || sf::Keyboard::isKeyPressed((sf::Keyboard::Left))){
        if (left() > 0){
            __rectangle.move((float) - Constants::SpeedRacket * time, 0);
        }
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::D) || sf::Keyboard::isKeyPressed(sf::Keyboard::Right)){
        if (right() < Constants::WindowSizeX){
            __rectangle.move((float)Constants::SpeedRacket * time, 0);
        }
    }
}
