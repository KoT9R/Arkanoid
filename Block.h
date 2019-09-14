//
// Created by Denis on 2019-08-13.
//

#ifndef KURSWORK_BLOCK_H
#define KURSWORK_BLOCK_H

#include "Rectangle.h"

class Block: public Rectangle  {
public:
    Block (sf::RenderWindow *window, sf::Vector2f const &position);
    void draw() const;
    int                __life;
private:
    sf::RenderWindow  *__window;
};


#endif //KURSWORK_BLOCK_H
