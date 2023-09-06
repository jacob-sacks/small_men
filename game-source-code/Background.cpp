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
    this->background1_.setPosition(-10.f*frameWidth_,0.f);

    this->background2_.setTexture(this->texture_);
    this->background2_.scale(this->xScale_,this->yScale_);
    this->background2_.setPosition(-3.f*frameWidth_,0.f);

    this->background3_.setTexture(this->texture_);
    this->background3_.scale(this->xScale_,this->yScale_);
    this->background3_.setPosition(4.f*frameWidth_,0.f);
}

void Background::update(){
    this->teleport(&this->background1_);
    this->teleport(&this->background2_);
    this->teleport(&this->background3_);
}

void Background::move(const float dirX, const float dirY){
    this->background1_.move(this->movementSpeed_ * dirX, this->movementSpeed_*dirY);
    this->background2_.move(this->movementSpeed_ * dirX, this->movementSpeed_*dirY);
    this->background3_.move(this->movementSpeed_ * dirX, this->movementSpeed_*dirY);
}

void Background::turnHarry(const float dirX, const float dirY){
    if(dirX < 0.f){

    } else 
    if (dirX > 0.f){
               
    }
}

void Background::teleport(sf::Sprite *background){
    if (background->getPosition().x <= -13*frameWidth_){
        background->setPosition(8.f*frameWidth_, 0.f);
        return;
    }
    if (background->getPosition().x >= 7*frameWidth_){
        background->setPosition(-8.f*frameWidth_, 0.f);
    }
}

void Background::render(sf::RenderTarget *target){
    target->draw(this->background1_);
    target->draw(this->background2_);
    target->draw(this->background3_);
}

Background::~Background(){
}
