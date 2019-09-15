//
// Created by Denis on 14/09/2019.
//

#include "MovBlock.h"


MovBlock::MovBlock(sf::RenderWindow *window, sf::Vector2f const &position):
leftWall(true), rightWall(!leftWall), Block(window,position) {
        startPosition  = position.x;
        finishPosition = position.x + Constants::WidthBlock + Constants::FreeSpaceNearBlocks;
}

void MovBlock::update(float time) {
    if (leftWall){
        __rectangle.move(time * __speed, 0);
        if (__rectangle.getPosition().x > finishPosition){
            leftWall  = false;
            rightWall = true;
        }
    }
    if (rightWall){
        __rectangle.move(-time * __speed, 0);
        if (__rectangle.getPosition().x < startPosition){
            leftWall  = true;
            rightWall = false;
        }
    }
}

size_t MovBlock::get_score() {
    return 3;
}
