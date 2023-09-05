#include "HarryPotter.h"

#include <iostream>
using namespace std;

HarryPotter::HarryPotter()
{
    this->initTexture();
    this->initSprite();
    this->initVars();
}

void HarryPotter::initTexture()
{
    if(!this->texture.loadFromFile("resources/harry-potter-clipart-cute.png")){
        std::cout << "Error";
    }
 
}

void HarryPotter::initSprite()
{
    this->sprite.setTexture(this->texture);

    //Resize sprite
    //(x,y) --> (-x) flips yaxis
    this->sprite.scale(0.075f,0.075f);
}

void HarryPotter::initVars()
{
     this->movementSpeed = 1.f;
     this->attackCoolDownMax = 10.f;
     this->attackCoolDown = this->attackCoolDownMax;
}

void HarryPotter::update()
{
    this->updateCoolDown();
}

void HarryPotter::updateCoolDown()
{
    if(attackCoolDown <= attackCoolDownMax){
        this->attackCoolDown += 0.5f;
    }
}

const sf::Vector2f &HarryPotter::getPos() const
{
    return this->sprite.getPosition();
}

void HarryPotter::render(sf::RenderTarget& targert)
{
    targert.draw(this->sprite);
}

void HarryPotter::move(const float dirX, const float dirY)
{
    this->sprite.move(this->movementSpeed*dirX, this->movementSpeed * dirY);
}

const bool HarryPotter::canAttack()
{
    if(this->attackCoolDown >= this->attackCoolDownMax){
        this->attackCoolDown = 0.f;
        return true;
    }
    return false;
}

HarryPotter::~HarryPotter()
{
}
