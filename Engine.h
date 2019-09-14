//
// Created by Denis on 2019-08-07.
//

#ifndef KURSWORK_ENGINE_H
#define KURSWORK_ENGINE_H
#include "Racket.h"
#include "Ball.h"
#include "Constants.h"
#include <SFML/Graphics.hpp>
#include "Block.h"
#endif //KURSWORK_ENGINE_H

void CollisionRacketBall(Racket const &paddle, Ball &ball);
void CollisionBallBlock(Ball &ball,Block &block);
void CreateBlocks(int blockX, int blockY, std::vector <std::vector <Block>> &blocks, sf::RenderWindow *window);
void DrawBlocks(int blockX, int blockY, std::vector <std::vector <Block>> &blocks);
void DeleteBlocks(std::vector <std::vector <Block>> &blocks, Ball &ball);