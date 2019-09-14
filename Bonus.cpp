//
// Created by Denis on 12/09/2019.
//

#include "Bonus.h"


Bonus::Bonus(sf::RenderWindow *window, sf::Vector2f const &position):
    __window(window), Rectangle(Constants::WidthBonus, Constants::HeightBonus){
    __rectangle.setSize(sf::Vector2f(__rectangleWidth, __rectangleHeight));
    __rectangle.setOrigin(sf::Vector2f(__rectangleWidth / 2, __rectangleHeight / 2));
    __rectangle.setPosition(position);
}

void Bonus::draw() {
    __window->draw(__rectangle);
}