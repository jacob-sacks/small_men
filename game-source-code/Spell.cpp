#include "Spell.h"


Spell::Spell(){

}

Spell::Spell(sf::Texture* texture, float originX, float originY, float dirX, float dirY){
    this->texture_ = texture;
    this->initSpell(originX, originY, dirX, dirY);
}

void Spell::initSpell(float originX, float originY, float dirX, float dirY){
    this->spell_.setTexture(*texture_);
    this->spell_.setPosition(originX,originY);
    this->dirX_ = dirX;
    this->dirY_ = dirY;
    this->spell_.scale(0.03f,0.03f);
}


const sf::FloatRect Spell::getBounds() const{
    return this->spell_.getGlobalBounds();
}

void Spell::setRelativeSpeed(float phantomSpeed){
    this->phantomSpeed_ = phantomSpeed;
}

void Spell::update(){
    // auto tempSpeed = this->speed_*(this->direction_.x/(std::abs(this->direction_.x))); 
    this->spell_.move((this->speed_*this->dirX_ + this->phantomSpeed_),0.f);
}

void Spell::render(sf::RenderTarget *target){
    target->draw(this->spell_);
}

void Spell::print()
{
        std::cout << "Bullet Speed is " << speed_*this->dirX_ << "\nPhantom Speed is " << this->phantomSpeed_ << "\nRelative Speed is " << this->speed_*this->dirX_ + this->phantomSpeed_ << "\n";

}

Spell::~Spell(){

}
