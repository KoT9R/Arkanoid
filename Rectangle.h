//
// Created by Denis on 2019-08-13.
//

#ifndef KURSWORK_RECTANGLE_H
#define KURSWORK_RECTANGLE_H

#include "Constants.h"
#include "SFML/Graphics.hpp"

class Rectangle {
public:

    Rectangle(float width, float height):
            __rectangleHeight(height), __rectangleWidth(width){}

    float x      () const { return __rectangle.getPosition().x;}
    float y      () const { return __rectangle.getPosition().y;}
    float top    () const { return __rectangle.getPosition().y - __rectangleHeight / 2;}
    float bottom () const { return __rectangle.getPosition().y + __rectangleHeight / 2;}
    float right  () const { return __rectangle.getPosition().x + __rectangleWidth  / 2;}
    float left   () const { return __rectangle.getPosition().x - __rectangleWidth  / 2;}

    float __rectangleHeight;
    float __rectangleWidth;

    sf::RectangleShape __rectangle;
};


#endif //KURSWORK_RECTANGLE_H
