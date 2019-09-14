//
// Created by Denis on 2019-08-04.
//

#include "Ball.h"
#include "Constants.h"

Ball::Ball(sf::RenderWindow *window):
        __window (window), __ballRadius(Constants::RadiusBall), __ballSpeed(Constants::SpeedBall) ,
        __velocity(Constants::SpeedBall, Constants::SpeedBall), __life(1){
    float positionX = (float)Constants::WindowSizeX / 2;
    float positionY = Constants::PositionBallY;
    __shape.setRadius(__ballRadius);
    __shape.setOrigin(__ballRadius,__ballRadius);
    __shape.setPosition(positionX,positionY);
}
void Ball::draw() {
    __window->draw(__shape);
}

void Ball::update(float time) {

    if (left() < 0){
        __velocity.x = __ballSpeed;
    }else if (right () > Constants::WindowSizeX){
        __velocity.x = -__ballSpeed;
    }

    if (top() < 0){
        __velocity.y = __ballSpeed;
    }else if (bottom() > Constants::WindowSizeY){
        __velocity.y = -__ballSpeed;
    }
    __shape.move(__velocity * time);

}