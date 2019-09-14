//
// Created by Denis on 2019-08-04.
//
#include "Rectangle.h"
#ifndef KURSWORK_RACKET_H
#define KURSWORK_RACKET_H

class Racket: public Rectangle {
public:
    explicit Racket(sf::RenderWindow *window);
    void draw();
    void update(float time);

private:
    sf::RenderWindow* __window;
    int __score;


};


#endif //KURSWORK_RACKET_H
