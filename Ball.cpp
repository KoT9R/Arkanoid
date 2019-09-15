//
// Created by Denis on 2019-08-04.
//

#include "Ball.h"
#include "Constants.h"

void Ball::resize() {
    __ballRadius = __coefRadius * Constants::RadiusBall;
    __shape.setRadius(__ballRadius);
    __shape.setOrigin(__ballRadius,__ballRadius);
}

Ball::Ball(sf::RenderWindow *window):
        __window (window),__coefRadius(1), __ballSpeed(0),
        __velocity(0, 0), __life(1){
    float positionX = (float)Constants::WindowSizeX / 2;
    float positionY = Constants::PositionBallY;
    resize();
    __shape.setPosition(positionX,positionY);
}
void Ball::draw() {
    __window->draw(__shape);
}

bool Ball::update(float time, bool &trampoline) {

    updateSpeed();

    if (left() < 0){
        __velocity.x = __ballSpeed;
    }else if (right () > Constants::WindowSizeX){
        __velocity.x = -__ballSpeed;
    }

    if (top() < 0){
        __velocity.y = __ballSpeed;
    }else if (bottom() > Constants::WindowSizeY && !trampoline){
        --__life;
    }else if (bottom() > Constants::WindowSizeY && trampoline){
        __velocity.y = -__ballSpeed;
        trampoline = false;
    }
    if (__life <= 0)
        return true;
    __shape.move(__velocity * time);
    return false;

}

void Ball::set_default(float radius, float speed) {
    __ballRadius = radius;
    __ballSpeed  = speed;
    __velocity.x = speed;
    __velocity.y = -speed;
}

void Ball::update_with_racket(float time) {
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) || sf::Keyboard::isKeyPressed((sf::Keyboard::Left))){
        if (left() > 0){
            __shape.move((float) - Constants::SpeedRacket * time, 0);
        }
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::D) || sf::Keyboard::isKeyPressed(sf::Keyboard::Right)){
        if (right() < Constants::WindowSizeX){
            __shape.move((float)Constants::SpeedRacket * time, 0);
        }
    }
}

void Ball::updateSpeed() {
    if (__velocity.x < 0)
        __velocity.x = -__ballSpeed;
    else
        __velocity.x = __ballSpeed;

    if (__velocity.y < 0)
        __velocity.y = -__ballSpeed;
    else
        __velocity.y = __ballSpeed;

}

