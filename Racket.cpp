//
// Created by Denis on 2019-08-04.
//

#include "Racket.h"

void Racket::resize() {
    __rectangleWidth = width_racket_coef * Constants::WidthRacket;
    __rectangle.setSize(sf::Vector2f(__rectangleWidth, __rectangleHeight));
    __rectangle.setOrigin(sf::Vector2f(__rectangleWidth / 2, __rectangleHeight / 2));
}

Racket::Racket(sf::RenderWindow *window):
        __window(window), __score (0), speed(Constants::SpeedRacket), width_racket_coef(1),
        Rectangle(Constants::WidthRacket, Constants::HeightRacket){
    resize();
    __rectangle.setPosition(sf::Vector2f((float)Constants::WindowSizeX / 2, Constants::WindowSizeY - __rectangleHeight - Constants::HeightforRacket));
}

void Racket::draw() {
    __window->draw(__rectangle);
}

void Racket::update(float time) {
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) || sf::Keyboard::isKeyPressed((sf::Keyboard::Left))){
        if (left() > 0){
            __rectangle.move( - speed * time, 0);
        }
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::D) || sf::Keyboard::isKeyPressed(sf::Keyboard::Right)){
        if (right() < Constants::WindowSizeX){
            __rectangle.move(speed * time, 0);
        }
    }
}
