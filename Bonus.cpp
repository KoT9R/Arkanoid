//
// Created by Denis on 12/09/2019.
//

#include "Bonus.h"


int Bonus::quantity_bonus() {
    return 9;
}

name_bonus Bonus::GenerateBonus() {
    return (name_bonus)(rand() % quantity_bonus() + 1);
}

Bonus::Bonus(sf::RenderWindow *window, sf::Vector2f const &position):
    __window(window), nameBonus(GenerateBonus()), isDestroyed(false),
    Rectangle(Constants::WidthBonus, Constants::HeightBonus){
    __rectangle.setSize(sf::Vector2f(__rectangleWidth, __rectangleHeight));
    __rectangle.setOrigin(sf::Vector2f(__rectangleWidth / 2, __rectangleHeight / 2));
    __rectangle.setPosition(position);
}

void Bonus::draw() {
    __window->draw(__rectangle);
}

void Bonus::increase_helath(size_t &life) {
    ++life;
}

void Bonus::speed_up_down(float &speed, bool up_down) {
    if (up_down)
        speed += Constants::ChangeSpeed;
    else
        speed -= Constants::ChangeSpeed;
}

void Bonus::width_up_down(float &width, bool up_down) {
    if (up_down)
        width += Constants::ChangeWidth;
    else
        width -= Constants::ChangeWidth;
}

bool Bonus::trampoline() {
    return true;
}

void Bonus::update(float time) {

    if (__rectangle.getPosition().y > Constants::WindowSizeY){
        isDestroyed = true;
    }else{
        __rectangle.move(0,Constants::SpeedBonus * time);
    }

}

void Bonus::radius_up_down(float &radius, bool up_down) {
    if (up_down)
        radius += Constants::ChangeRadiusCoef;
    else
        radius -= Constants::ChangeRadiusCoef;
}