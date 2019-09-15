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
#include "MovBlock.h"
#endif //KURSWORK_ENGINE_H

void CollisionRacketBall(Racket const &paddle, Ball &ball);
void CollisionBallBlock(Ball &ball,Block *block);
void CreateBlocks(int blockX, int blockY, std::vector <std::vector <Block*>> &blocks, sf::RenderWindow *window);
void DrawBlocks(std::vector <std::vector <Block*>> &blocks);
int DeleteBlocks(std::vector <std::vector <Block*>> &blocks, Ball &ball, std::vector <Bonus> &bonuses);
void UseBonus(Ball &ball, Racket &paddle, std::vector <Bonus> &bonusObjects, bool &trampoline, std::vector <t_bonus> &activeBonuses, float timeStart);
void DeleteObjectBonus(std::vector <Bonus> &objectBonus);
void UpdateBlocks(std::vector <std::vector <Block*>> &blocks, float time);
void BonusUpdate(std::vector <Bonus> &bonusObjects, float time);
void BonusDraw(std::vector <Bonus> &bonusObjects);
void BonusLife(float time, std::vector <t_bonus> &activeBonus, Racket &paddle, Ball &myBall, bool &trampoline);