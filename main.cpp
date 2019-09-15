#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <sstream>
#include "Engine.h"


void ShowText(sf::RenderWindow &window,sf::Text &hp,sf::Text &tScore, size_t life, size_t score){
    std::ostringstream playerScore;
    std::ostringstream playerLife;
    playerScore << score;
    playerLife << life;
    tScore.setString("Score: " + playerScore.str());
    playerScore << life;
    hp.setString("Health: " + playerLife.str());
    window.draw(tScore);
    window.draw(hp);
}

int main() {

// Create the main window
    sf::Clock clock;
    sf::RenderWindow window(sf::VideoMode(Constants::WindowSizeX, Constants::WindowSizeY), "Arkanoid");

    bool spacePressed = false;
    unsigned int spaceTime = 0;
    bool trampoline = false;
    bool gameOver = false;
    float timeNow = 0;


    sf::Font font;
    font.loadFromFile("/Users/denis/CLionProjects/С++/KursWork/arial.ttf");
    sf::Text hp("",font,40);
    sf::Text score("", font, 40);
    hp.setPosition(1700,1000);
    score.setPosition(50, 1000);

    Racket padle(&window);
    Ball myball(&window);
    std::vector <Bonus> bonusesObject;
    std::vector <t_bonus> activeBonus;
    std::vector <std::vector <Block*>> blocks;
    CreateBlocks(Constants::BlockX, Constants::BlockY, blocks, &window);

    while (window.isOpen()){
        sf::Event event;
        float time = clock.getElapsedTime().asMicroseconds();
        clock.restart();
        time = time /  1600;
        timeNow += time;
        srand(time);
        while(window.pollEvent(event)){
            if (event.type == sf::Event::Closed ||
                    (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape))
                window.close();
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && spaceTime == 0){
            myball.set_default();
            ++spaceTime;
            spacePressed = true;
        }
        if (!spacePressed) myball.update_with_racket(time);

        if (spacePressed) CollisionRacketBall(padle,myball);


        padle.__score += DeleteBlocks(blocks, myball, bonusesObject);
        UseBonus(myball,padle,bonusesObject,trampoline,activeBonus,timeNow);
        DeleteObjectBonus(bonusesObject);
        BonusLife(timeNow,activeBonus,padle,myball,trampoline);
        //trampoline = true;

        gameOver = myball.update(time,trampoline);
        if (gameOver)
            return EXIT_SUCCESS;
        padle.update(time);
        BonusUpdate(bonusesObject,time);
        UpdateBlocks(blocks,time);


        window.clear();
        DrawBlocks( blocks);
        BonusDraw(bonusesObject);
        myball.draw();
        padle.draw();
        ShowText(window,hp,score,myball.__life,padle.__score);


        window.display();

    }

    return EXIT_SUCCESS;
}