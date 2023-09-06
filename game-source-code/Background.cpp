#include "Background.h"

Background::Background(){
    this->initTexture();
    this->initSprite();
}

void Background::initTexture(){
    if(!this->texture_.loadFromFile("resources/background.png")){
        std::cout << "Error";
    }
}

void Background::initSprite(){
    this->background1_.setTexture(this->texture_);
    this->background1_.scale(this->xScale_,this->yScale_);
    this->background1_.setPosition(-3.f*frameWidth_,0.f);
}

void Background::update(){

}

void Background::move(const float dirX, const float dirY)
{
    this->background1_.move(this->movementSpeed_ * dirX, this->movementSpeed_*dirY);
}

void Background::turnHarry(const float dirX, const float dirY){
    if(dirX < 0.f){

    } else 
    if (dirX > 0.f){
               
    }
}



void Background::render(sf::RenderTarget *target){
    target->draw(this->background1_);
}

Background::~Background(){
}
