#include "Spell.h"

Spell::Spell(){

}
Spell::Spell(sf::Texture* texture, float originX, float originY, float dirX, float dirY, float movementSpeed){
    this->shape_.setTexture(*texture);
    this->shape_.setPosition(originX,originY);
    this->direction_.x = dirX;
    this->direction_.y = dirY;
    this->movementSpeed_ = movementSpeed;
        this->shape_.scale(0.03f,0.03f);

}

Spell::~Spell(){

}

const sf::FloatRect Spell::getBounds() const{
    return this->shape_.getGlobalBounds();
}

void Spell::update(){
    this->shape_.move(this->movementSpeed_*this->direction_);
}

void Spell::render(sf::RenderTarget *target){
    target->draw(this->shape_);
}
