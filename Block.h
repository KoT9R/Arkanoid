//
// Created by Denis on 2019-08-13.
//

#ifndef KURSWORK_BLOCK_H
#define KURSWORK_BLOCK_H

#include "Rectangle.h"
#include "Bonus.h"

class Block: public Rectangle  {
public:
    Block (sf::RenderWindow *window, sf::Vector2f const &position);
    virtual void draw() const;
    virtual void update(float time);
    virtual size_t get_score();

    int  __life;
    bool __bonus_exist;

    sf::RenderWindow* get_window();
private:
    sf::RenderWindow  *__window;
};


#endif //KURSWORK_BLOCK_H
