//
// Created by Denis on 2019-08-13.
//

#include "Block.h"
#include "Constants.h"

Block::Block(sf::RenderWindow *window, sf::Vector2f const &position):
            __window(window),__life(1), Rectangle(Constants::WidthBlock, Constants::HeightBlock) {
    __rectangle.setSize(sf::Vector2f(__rectangleWidth, __rectangleHeight));
    __rectangle.setOrigin(sf::Vector2f(__rectangleWidth / 2, __rectangleHeight / 2));
    __rectangle.setPosition(position);
}

void Block::draw() const {
    __window->draw(__rectangle);
}