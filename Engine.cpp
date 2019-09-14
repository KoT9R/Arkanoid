//
// Created by Denis on 2019-08-07.
//

#include "Engine.h"
#include <cmath>

bool IsCollisionRacket(Racket const &paddle, Ball const &ball){
    return paddle.right() >= ball.left() && paddle.left() <= ball.right()
            && paddle.bottom() >= ball.top() && paddle.top() <= ball.bottom();
}

bool IsCollisionBlock(Block const &block, Ball const &ball){
    return block.right() >= ball.left() && block.left() <= ball.right()
           && block.bottom() >= ball.top() && block.top() <= ball.bottom();
}

void CollisionRacketBall(Racket const &paddle, Ball &ball){
    if (!IsCollisionRacket(paddle, ball)) return;
    ball.__velocity.y = -ball.__ballSpeed;

    if (ball.x() < paddle.x() ) { ball.__velocity.x = -ball.__ballSpeed; }
    else { ball.__velocity.x = ball.__ballSpeed; }
}

void PushBonus(std::vector <std::vector <Block>> &blocks){

}

void CollisionBallBlock(Ball &ball,Block &block){
    if (!IsCollisionBlock(block, ball)) return;
    --block.__life;
    ++ball.__score;

    float overlapLeft   = ball.right()  - block.left();
    float overlapRight  = ball.left()   - block.right();
    float overlapTop    = ball.bottom() - block.top();
    float overlapBottom = ball.top()    - block.bottom();

    bool  ballFromRight  = abs(overlapRight)  > abs(overlapLeft);
    bool  ballFromBottom = abs(overlapBottom) > abs(overlapTop);

    float minOverlapX{ballFromRight ? overlapLeft : overlapRight};
    float minOverlapY{ballFromBottom ? overlapTop : overlapBottom};

    if(abs(minOverlapX) < abs(minOverlapY))
        ball.__velocity.x = ballFromRight ? -Constants::SpeedBall : Constants::SpeedBall;
    else
        ball.__velocity.y = ballFromBottom ? -Constants::SpeedBall : Constants::SpeedBall;
}

void DeleteBlocks(std::vector <std::vector <Block>> &blocks, Ball &ball){
    for (auto & block : blocks){
        for (auto & j : block){
            CollisionBallBlock(ball,j);
        }
    }
    //blocks.erase(std::remove_if(std::begin(blocks),std::end(blocks),[](const Block& block){ return block.__life; }),std::end(blocks));
    for (auto & i : blocks){
        i.erase(remove_if(begin(i), end(i),[](const Block& block){ return !(bool)block.__life; }), end(i));
    }


}


void CreateBlocks(int const blockX, int const blockY, std::vector <std::vector <Block>> &blocks, sf::RenderWindow *window){
    float firstPositionX = Constants::FreeSpaceLeftRight * Constants::WidthBlock + Constants::WidthBlock / 2 - 100;
    float firstPositionY = Constants::FreeSpaceTop * Constants::HeightBlock + Constants::HeightBlock / 2;

    sf::Vector2f position (firstPositionX,firstPositionY);
    for (size_t i = 0; i < blockY; ++i ){
        std::vector <Block> cash;
        for (size_t j = 0; j < blockX; ++j){
            position.x += Constants::WidthBlock + Constants::FreeSpaceNearBlocks;
            Block newBlock(window,position);
            cash.push_back(newBlock);
        }
        position.x  = firstPositionX;
        position.y += Constants::HeightBlock + Constants::FreeSpaceNearBlocks;
        blocks.push_back(cash);
    }
}

void DrawBlocks(int const blockX, int const blockY, std::vector <std::vector <Block>> &blocks){
    for (size_t i = 0; i < blockY; ++i){
        for (size_t j = 0; j < blockX; ++j){
            blocks[i][j].draw();
        }
    }
}
