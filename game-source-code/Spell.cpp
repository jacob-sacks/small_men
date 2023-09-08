#include "Spell.h"


Spell::Spell(){

}

Spell::Spell(sf::Texture* texture, float originX, float originY, float dirX, float dirY){
    this->texture_ = texture;
    this->initSpell(originX, originY, dirX, dirY, 0.f);
}

Spell::Spell(sf::Texture* texture, float originX, float originY, float dirX, float dirY, float travelingXVelocity){
    this->texture_ = texture;
    this->initSpell(originX, originY, dirX, dirY, travelingXVelocity);
}


void Spell::initSpell(float originX, float originY, float dirX, float dirY, float travelingXVelocity){
    this->spell_.setTexture(*texture_);
    this->spell_.setPosition(originX,originY);
    this->dirX_ = dirX;
    this->dirY_ = dirY;
    this->phantomVelocity_ = travelingXVelocity;
    this->spell_.scale(0.03f,0.03f);
}


const sf::FloatRect Spell::getBounds() const{
    return this->spell_.getGlobalBounds();
}

void Spell::updatePhantomVelocity(float travelingXVelocity){
    this->phantomVelocity_ = travelingXVelocity;
}

void Spell::update(){
    // auto tempSpeed = this->speed_*(this->direction_.x/(std::abs(this->direction_.x))); 
    this->actualVelocity_ = this->speed_*this->dirX_ + this->phantomVelocity_*abs(this->dirX_);
    this->spell_.move((this->actualVelocity_),0.f);
    //std::cout << "Phantom: " << this->phantomVelocity_*abs(this->phantomVelocity_) << "\nActual: " << this->actualVelocity_ << "\n";
}

void Spell::render(sf::RenderTarget *target){
    target->draw(this->spell_);
}

float Spell::getActualVelocity()
{
    return this->actualVelocity_;
}

Spell::~Spell(){

}
