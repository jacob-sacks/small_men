#include "HarryPotter.h"

#include <iostream>
using namespace std;

HarryPotter::HarryPotter()
{
    this->initTexture();
    this->initSprite();
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


void HarryPotter::update()
{
    this->updateCoolDown();
}

void HarryPotter::updateCoolDown()
{
    if(this->attackCoolDown_ <= this->attackCoolDownMax_){
        this->attackCoolDown_ += 0.5f;
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
    
    if(dirX > 0.f && this->sprite.getScale().x < 0.f){
        this->sprite.setScale(0.075f,0.075f);
        this->sprite.setOrigin(0.f,0.f);
    }else if (dirX < 0.f && this->sprite.getScale().x > 0.f){
            this->sprite.setScale(-0.075f,0.075f);
            this->sprite.setOrigin(this->sprite.getGlobalBounds().width/0.075f, 0.f);
        }

    this->sprite.move(this->movementSpeed_*dirX, this->movementSpeed_ * dirY);
}

const bool HarryPotter::canAttack()
{
    if(this->attackCoolDown_ >= this->attackCoolDownMax_){
        this->attackCoolDown_ = 0.f;
        return true;
    }
    return false;
}

HarryPotter::~HarryPotter()
{
}
