//
// Created by Denis on 2019-08-13.
//

#include "Block.h"
#include "Constants.h"
#include <random>

Block::Block(sf::RenderWindow *window, sf::Vector2f const &position):
            __window(window),__life(1), Rectangle(Constants::WidthBlock, Constants::HeightBlock) {
    __rectangle.setSize(sf::Vector2f(__rectangleWidth, __rectangleHeight));
    __rectangle.setOrigin(sf::Vector2f(__rectangleWidth / 2, __rectangleHeight / 2));
    __rectangle.setPosition(position);
    __bonus_exist = !(rand() % 5);//Constants::PercentBonus(20) != 0;
}

void Block::draw() const {
    __window->draw(__rectangle);
}

sf::RenderWindow* Block::get_window() {
    return __window;
}

void Block::update(float time) {
    __rectangle.move(time * 0,time * 0);
}

size_t Block::get_score() {
    return 1;
}