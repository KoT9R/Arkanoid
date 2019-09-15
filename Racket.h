//
// Created by Denis on 2019-08-04.
//
#include "Rectangle.h"
#ifndef KURSWORK_RACKET_H
#define KURSWORK_RACKET_H

class Racket: public Rectangle {
public:
    explicit Racket(sf::RenderWindow *window);
    void resize();
    void draw();
    void update(float time);

    float speed;
    float width_racket_coef;
    int __score;
private:
    sf::RenderWindow* __window;
};


#endif //KURSWORK_RACKET_H
