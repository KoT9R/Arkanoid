//
// Created by Denis on 14/09/2019.
//

#ifndef KURSWORK_MOVBLOCK_H
#define KURSWORK_MOVBLOCK_H

#include "Block.h"


class MovBlock : public Block {
public:
    MovBlock(sf::RenderWindow *window, sf::Vector2f const &position);
    void update(float time);
    size_t get_score();
private:
    float __speed {Constants::SpeedBlock};
    float startPosition;
    float finishPosition;
    bool leftWall;
    bool rightWall;

    float Position(sf::Vector2f const &position);
};


#endif //KURSWORK_MOVBLOCK_H
