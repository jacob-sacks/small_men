#include "Spell.h"


Spell::Spell()
{
}
Spell::Spell(sf::Texture* texture, float originX, float originY, float dirX, float dirY){
    this->texture_ = texture;
    this->initSpell(originX, originY, dirX, dirY);
}

void Spell::initSpell(float originX, float originY, float dirX, float dirY){
    this->spell_.setTexture(*texture_);
    this->spell_.setPosition(originX,originY);
    this->direction_.x = dirX;
    this->direction_.y = dirY;
    this->spell_.scale(0.03f,0.03f);
}


const sf::FloatRect Spell::getBounds() const{
    return this->spell_.getGlobalBounds();
}

void Spell::update(){
    this->spell_.move(this->speed_*this->direction_);
}

void Spell::render(sf::RenderTarget *target){
    target->draw(this->spell_);
}

Spell::~Spell(){

}
