//
// Created by Denis on 12/09/2019.
//

#ifndef KURSWORK_BONUS_H
#define KURSWORK_BONUS_H

#include "Rectangle.h"
#include <vector>

enum name_bonus{
    INCREASE_HEALTH,
    SPEED_DOWN_BALL,
    SPEED_UP_BALL,
    SPEED_DOWN_RACKET,
    SPEED_UP_RACKET,
    RADIUS_UP,
    RADIUS_DOWN,
    WIDTH_DOWN,
    WIDTH_UP,
    TRAMPOLINE
};

struct t_bonus{
    name_bonus name_bonus;
    float time;
};

class Bonus: public Rectangle{
public:
    Bonus(sf::RenderWindow *window, sf::Vector2f const &position);
    void draw();
    void update(float time);

    void increase_helath (size_t &life);
    void speed_up_down(float &speed, bool up_down);
    void width_up_down(float &width, bool up_down);
    void radius_up_down(float &radius, bool up_down);
    bool trampoline();
    int quantity_bonus();

    name_bonus nameBonus;
    bool isDestroyed;

private:
    name_bonus GenerateBonus();


    sf::RenderWindow *__window;
};


enum up_down{
    DOWN,
    UP
};



#endif //KURSWORK_BONUS_H
