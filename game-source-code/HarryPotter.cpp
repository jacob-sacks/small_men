#include "HarryPotter.h"

#include <iostream>
using namespace std;

HarryPotter::HarryPotter()
{
    this->initTexture();
    this->initSprite();
    this->movementSpeed = 10.f;
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
}

void HarryPotter::render(sf::RenderTarget& targert)
{
    targert.draw(this->sprite);
}

void HarryPotter::move(const float dirX, const float dirY)
{
    this->sprite.move(this->movementSpeed*dirX, this->movementSpeed * dirY);
}

HarryPotter::~HarryPotter()
{
}
