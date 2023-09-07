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
    this->background1_.move(this->speed_ * dirX, this->speed_*dirY);
    this->background2_.move(this->speed_ * dirX, this->speed_*dirY);
    this->background3_.move(this->speed_ * dirX, this->speed_*dirY);
}



void Background::teleport(sf::Sprite *background){
    if (background->getPosition().x <= -15*frameWidth_){
        background->setPosition(6.f*frameWidth_, 0.f);
        return;
    }
    if (background->getPosition().x >= 9*frameWidth_){
        background->setPosition(-6.f*frameWidth_, 0.f);
    }
}

const float Background::getSpeed(){
    return this->speed_;
}

void Background::render(sf::RenderTarget *target)
{
    target->draw(this->background1_);
    target->draw(this->background2_);
    target->draw(this->background3_);
}

Background::~Background(){
}
