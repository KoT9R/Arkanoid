//
// Created by Denis on 2019-08-04.
//

#ifndef KURSWORK_BALL_H
#define KURSWORK_BALL_H

#include <SFML/Graphics.hpp>

class Ball {
public:
    explicit Ball (sf::RenderWindow *window);
    void draw();
    void update(float time);

    float x      () const { return __shape.getPosition().x;}
    float y      () const { return __shape.getPosition().y;}
    float top    () const { return __shape.getPosition().y - __ballRadius;}
    float bottom () const { return __shape.getPosition().y + __ballRadius;}
    float right  () const { return __shape.getPosition().x + __ballRadius;}
    float left   () const { return __shape.getPosition().x - __ballRadius;}

    float  __ballRadius;
    float  __ballSpeed;
    size_t __life;
    size_t __score = {0};
    sf::Vector2f __velocity{};

private:
    sf::RenderWindow *__window;
    sf::CircleShape __shape;



};


#endif //KURSWORK_BALL_H
