#include "DeathEater.h"

void DeathEater::initVars(){
        type = 0;
        hp = 0;
        hpMax = 10;
        damage = 1;
        points = 5;
}

void DeathEater::initShape(){
    this->shape.setRadius(rand()%20 + 20);
    this->shape.setPointCount(rand()%100 + 3);
}

DeathEater::DeathEater(float posX, float posY){
    this->initShape();
    this->initVars();
    this->shape.setPosition(posX, posY);
}

void DeathEater::update(){

}

void DeathEater::render(sf::RenderTarget *target){
    target->draw(this->shape);
}

DeathEater::~DeathEater(){
}
