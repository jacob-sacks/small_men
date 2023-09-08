// #include "HarryPotter.h"

// #include <iostream>
// using namespace std;

// HarryPotter::HarryPotter(){
//     this->initTexture();
//     this->initHarryPotter();
// }

// void HarryPotter::initTexture(){
//     if(!this->texture.loadFromFile("resources/harry_potter_glow.png")){
//         std::cout << "Error";
//     }
// }

// void HarryPotter::initHarryPotter(){
//     this->harryPotter_.setTexture(this->texture);
    //Doesnt use startWdith and Height
    // this->harryPotter_.setPosition(this->startWidth_,this->startHeight_);
//     this->harryPotter_.scale(0.075f,0.075f);
// }


// void HarryPotter::update(){
//     this->updateCoolDown();
// }

// void HarryPotter::updateCoolDown(){
//     if(this->attackCoolDown_ <= this->attackCoolDownMax_){
//         this->attackCoolDown_ += 0.5f;
//     }
// }


// const sf::Vector2f &HarryPotter::getPos() const{
//     return this->harryPotter_.getPosition();
// }


// void HarryPotter::render(sf::RenderTarget& targert){
//     targert.draw(this->harryPotter_);
// }

// void HarryPotter::move(const float dirX, const float dirY){
//     this->harryPotter_.move(this->speed_*dirX, this->speed_ * dirY);
// }

// void HarryPotter::flip(DIRECTION dir){
//     if(dir==DIRECTION::RIGHT){
//         this->harryPotter_.setScale(0.075f,0.075f);
//         this->harryPotter_.setOrigin(0.f,0.f);
//         return;
//     }  
//     if (dir==DIRECTION::LEFT){
//         this->harryPotter_.setScale(-0.075f,0.075f);
//         this->harryPotter_.setOrigin(this->harryPotter_.getGlobalBounds().width/0.075f, 0.f);  
//         return;     
//     }
// }

// DIRECTION HarryPotter::mustTurn(const float dirX, const float dirY){
//     if(dirX < 0.f && this->harryPotter_.getScale().x < 0.f){
//         return DIRECTION::RIGHT;
//     }
//     if (dirX > 0.f && this->harryPotter_.getScale().x > 0.f){
//         return  DIRECTION::LEFT;
//     }
//     return DIRECTION::NO_TURN;
// }


// const bool HarryPotter::canAttack(){
//     if(this->attackCoolDown_ >= this->attackCoolDownMax_){
//         return true;
//     }
//     return false;
// }

// void HarryPotter::resetCoolDown(){
//     this->attackCoolDown_ = 0.f;
// }

// const float HarryPotter::getStartWidth(){
//     return this->startWidth_;
// }

float HarryPotter::getSpeed(){
    return this->speed_;
}

// HarryPotter::~HarryPotter(){
// }
