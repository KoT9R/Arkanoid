//
// Created by Denis on 12/09/2019.
//

#ifndef KURSWORK_BONUS_H
#define KURSWORK_BONUS_H

#include "Rectangle.h"

class Bonus: public Rectangle{
public:
    Bonus(sf::RenderWindow *window, sf::Vector2f const &position);
    void draw();
private:
    sf::RenderWindow *__window;
};


#endif //KURSWORK_BONUS_H
