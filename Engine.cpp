//
// Created by Denis on 2019-08-07.
//

#include "Engine.h"
#include <cmath>

bool IsCollisionRacket(Racket const &paddle, Ball const &ball){
    return paddle.right() >= ball.left() && paddle.left() <= ball.right()
            && paddle.bottom() >= ball.top() && paddle.top() <= ball.bottom();
}

bool IsCollisionBlock(Block const *block, Ball const &ball){
    return block->right() >= ball.left() && block->left() <= ball.right()
           && block->bottom() >= ball.top() && block->top() <= ball.bottom();
}

bool IsCollisionBonus(Racket const &paddle, Bonus const &bonus){
    return paddle.right() >= bonus.left() && paddle.left() <= bonus.right()
            && paddle.bottom() >= bonus.top() && paddle.top() <= bonus.bottom();
}

void CollisionRacketBall(Racket const &paddle, Ball &ball){
    if (!IsCollisionRacket(paddle, ball)) return;
    ball.__velocity.y = -ball.__ballSpeed;

    if (ball.x() < paddle.x() ) { ball.__velocity.x = -ball.__ballSpeed; }
    else { ball.__velocity.x = ball.__ballSpeed; }
}


void CreateBonus(Block *block, std::vector <Bonus> &bonuses){
    if (block->__bonus_exist)
        bonuses.emplace_back(block->get_window(),sf::Vector2f(block->x(),block->bottom()));
}

void DeleteObjectBonus(std::vector <Bonus> &objectBonus){
    objectBonus.erase(remove_if(objectBonus.begin(), objectBonus.end(),
                                [](const Bonus& bonus){
                                    return bonus.isDestroyed;
                                }),objectBonus.end());
}


void UseBonus(Ball &ball, Racket &paddle, std::vector <Bonus> &bonusObjects, bool &trampoline, std::vector <t_bonus> &activeBonuses, float timeStart){
    for (auto &bonus : bonusObjects){
        if (!IsCollisionBonus(paddle,bonus)) continue;
        bonus.isDestroyed = true;
        switch (bonus.nameBonus)
        {
            case INCREASE_HEALTH:
                bonus.increase_helath(ball.__life);
                break;
            case SPEED_DOWN_BALL:
                bonus.speed_up_down(ball.__ballSpeed, DOWN);
                break;
            case SPEED_UP_BALL:
                bonus.speed_up_down(ball.__ballSpeed, UP);
                break;
            case SPEED_DOWN_RACKET:
                bonus.speed_up_down(paddle.speed, DOWN);
                break;
            case SPEED_UP_RACKET:
                bonus.speed_up_down(paddle.speed, UP);
                break;
            case WIDTH_DOWN:
                bonus.width_up_down(paddle.width_racket_coef, DOWN);
                paddle.resize();
                break;
            case WIDTH_UP:
                bonus.width_up_down(paddle.width_racket_coef, UP);
                paddle.resize();
                break;
            case TRAMPOLINE:
                trampoline = bonus.trampoline();
                break;
            case RADIUS_UP:
                bonus.radius_up_down(ball.__coefRadius,UP);
                ball.resize();
                break;
            case RADIUS_DOWN:
                bonus.radius_up_down(ball.__coefRadius,DOWN);
                ball.resize();
                break;
        }
        activeBonuses.emplace_back(t_bonus{bonus.nameBonus,timeStart});
    }

}

void CollisionBallBlock(Ball &ball,Block *block){
    if (!IsCollisionBlock(block, ball)) return;
    --block->__life;
    ++ball.__score;

    float overlapLeft   = ball.right()  - block->left();
    float overlapRight  = ball.left()   - block->right();
    float overlapTop    = ball.bottom() - block->top();
    float overlapBottom = ball.top()    - block->bottom();

    bool ballFromLeft(abs(overlapLeft) < abs(overlapRight));
    bool ballFromTop(abs(overlapTop) < abs(overlapBottom));

    float minOverlapX{ballFromLeft ? overlapLeft : overlapRight};
    float minOverlapY{ballFromTop ? overlapTop : overlapBottom};

    if(abs(minOverlapX) < abs(minOverlapY))
        ball.__velocity.x = ballFromLeft? -ball.__ballSpeed : ball.__ballSpeed;
    else
        ball.__velocity.y = ballFromTop ? -ball.__ballSpeed : ball.__ballSpeed;
}

int DeleteBlocks(std::vector <std::vector <Block*>> &blocks, Ball &ball, std::vector <Bonus> &bonuses){
    int score = 0;
    for (auto  &block : blocks){
        for (auto  &j : block){
            CollisionBallBlock(ball,j);
            if (j->__bonus_exist && !j->__life)
                CreateBonus(j,bonuses);
            if (!j->__life){
                score += j->get_score();
            }

        }
    }
    //blocks.erase(std::remove_if(std::begin(blocks),std::end(blocks),[](const Block& block){ return block.__life; }),std::end(blocks));
    for (auto & i : blocks){
        i.erase(remove_if(begin(i), end(i),
                [](const Block* block){
            return !(bool)block->__life;
        }), end(i));
    }
    return score;
}



void CreateBlocks(int const blockX, int const blockY, std::vector <std::vector <Block*>> &blocks, sf::RenderWindow *window){
    float firstPositionX = Constants::FreeSpaceLeftRight * Constants::WidthBlock - Constants::WidthBlock * 3;
    float firstPositionY = Constants::FreeSpaceTop * Constants::HeightBlock + Constants::HeightBlock / 2;

    sf::Vector2f position (firstPositionX,firstPositionY);
    for (size_t i = 0; i < blockY; ++i ){
        std::vector <Block*> cash;
        for (size_t j = 0; j < blockX; ++j){
            position.x += Constants::WidthBlock + Constants::FreeSpaceNearBlocks;
            auto* newBlockSimple = new Block(window,position);
            auto* newBlockThreeLife = new Block (window,position);
            newBlockThreeLife->__life += 2;
            auto *newMovBlock = new MovBlock(window,position);
            Block *a;
            switch(rand() % 4){
                case 0:
                    cash.push_back(newBlockSimple);
                    break;
                case 1:
                    cash.push_back(newBlockThreeLife);
                    break;
                case 2:
                    a = newMovBlock;
                    cash.push_back(a);
                    position.x += Constants::WidthBlock + Constants::FreeSpaceNearBlocks;
                    break;
                case 3:
                    a = newMovBlock;
                    a->__life += 2;
                    cash.push_back(a);
                    position.x += Constants::WidthBlock + Constants::FreeSpaceNearBlocks;
                    break;
            }
        }
        position.x  = firstPositionX;
        position.y += Constants::HeightBlock + Constants::FreeSpaceNearBlocks;
        blocks.push_back(cash);
    }
}

void DrawBlocks(std::vector <std::vector <Block*>> &blocks){
    for (auto &y : blocks)
        for (auto &x : y)
            x->draw();
}

void UpdateBlocks(std::vector <std::vector <Block*>> &blocks, float time){
    for (auto &block : blocks){
        for (auto &i : block){
            i->update(time);
        }
    }
}

void SetDefault(t_bonus &activeBonus,Racket &paddle, Ball &myBall, bool &trampoline){
    switch (activeBonus.name_bonus)
    {
        case INCREASE_HEALTH:
        case SPEED_DOWN_BALL:
            myBall.__ballSpeed += Constants::SpeedBall;
            break;
        case SPEED_UP_BALL:
            myBall.__ballSpeed -= Constants::SpeedBall;
            break;
        case SPEED_DOWN_RACKET:
            paddle.speed += Constants::SpeedRacket;
            break;
        case SPEED_UP_RACKET:
            paddle.speed -= Constants::SpeedRacket;
            break;
        case WIDTH_DOWN:
            paddle.width_racket_coef += Constants::ChangeWidth;
            paddle.resize();
            break;
        case WIDTH_UP:
            paddle.width_racket_coef -= Constants::ChangeWidth;
            paddle.resize();
            break;
        case TRAMPOLINE:
            trampoline = false;
            break;
        case RADIUS_UP:
            myBall.__coefRadius -= Constants::ChangeRadiusCoef;
            myBall.resize();
            break;
        case RADIUS_DOWN:
            myBall.__coefRadius += Constants::ChangeRadiusCoef;
            myBall.resize();
            break;
    }
}

void BonusLife(float time, std::vector <t_bonus> &activeBonus, Racket &paddle, Ball &myBall, bool &trampoline){

    auto newEnd = remove_if(activeBonus.begin(), activeBonus.end(),
    [time,&myBall,&paddle,&trampoline](t_bonus &bonus){
        if (fabs(time - bonus.time) > Constants::BonusTime){
            SetDefault(bonus,paddle,myBall,trampoline);
            return true;
        }else
            return false;

    });
    activeBonus.erase(newEnd,activeBonus.end());

}

void BonusDraw(std::vector <Bonus> &bonusObjects){
    for (auto &i: bonusObjects){
        i.draw();
    }
}

void BonusUpdate(std::vector <Bonus> &bonusObjects, float time){
    for (auto &i : bonusObjects ){
        i.update(time);
    }
}