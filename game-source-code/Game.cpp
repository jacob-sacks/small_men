#include <iostream>
#include <iomanip>
// #include "Game.h"
// #include "HarryPotter.h"

// Game::Game(){
//     this->initWindow();
    this->initTextures();
    // this->initVars();
// }

void Game::turnTransition()
{
    const float leftDir = this->harry_->getStartWidth();
    const float rightDir = this->screenWidth - this->harry_->getStartWidth();  
    switch (harryIsTurning_)
    {
    case DIRECTION::NO_TURN:
        return;
        break;
    case DIRECTION::LEFT:
            if(this->harry_->getPos().x >= rightDir){
                this->harryIsTurning_ = DIRECTION::NO_TURN;
            }
            else{
                this->harry_->move(3.f,0.f);
                this->background_->move(3.f,0.f);
            }

        break;
    case DIRECTION::RIGHT:
         if(this->harry_->getPos().x <= leftDir){
                this->harryIsTurning_ = DIRECTION::NO_TURN;
            }
            else{
                this->harry_->move(-3.f,0.f);
                this->background_->move(-3.f,0.f);
            }
        break;
    default:
        break;
    }
}

// void Game::initWindow()
// {
//     this->window_ = new sf::RenderWindow(sf::VideoMode(this->screenWidth, this->screenHeight), "Game", sf::Style::Close | sf::Style::Titlebar);
//     this->window_->setVerticalSyncEnabled(true);
// }

void Game::initTextures(){
    this->textures_.push_back(new sf::Texture());
    this->textures_[static_cast<int>(texturesTypes::harrySpell)]->loadFromFile("resources/harry_spell.png");
}

void Game::initVars(){
    this->initBackground();
    this->initHarryPotter();
    this->shootDirection = DIRECTION::RIGHT;
    this->harryIsTurning_ = DIRECTION::NO_TURN;
}

// void Game::initHarryPotter(){
//     this->harry_ = new HarryPotter();
     this->deathEater_ = new DeathEater(20.f, 20.f);
// }

// void Game::initBackground(){
//     this->background_ = new Background();
// }


//void Game::run(){
//    while(this->window_->isOpen()){
        // this->update();
//        this->render();
//    }
//}

// void Game::update(){
//    this->updatePollEvents();
//    this->updateInput();
   this->background_->update();
   this->updateSpell();
   this->harry_->update();
   this->turnTransition();
   
}


// void Game::updatePollEvents(){
//     sf::Event e;
//     while (this->window_->pollEvent(e)){
//         if(e.Event::type == sf::Event::Closed)
//             this->window_->close();
//         if(e.Event::KeyPressed && e.Event::key.code == sf::Keyboard::Escape)
//             this->window_->close();    
//     }
// }

// void Game::updateInput(){
//     if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up))
//         this->harry_->move(0.f,-1.f);
//     if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down))
//         this->harry_->move(0.f,1.f);
    if(sf::Keyboard::isKeyPressed(sf::Keyboard:: Key::Right)){
        this->harryTurns_ = this->harry_->mustTurn(-1.f,0.f);
        if (this->harryTurns_ == DIRECTION::RIGHT){
            this->harry_->flip(harryTurns_); 
            this->harryIsTurning_ = DIRECTION::RIGHT; 
        }
        else {
            // this->background_->move(-1.f,0.f);
        }
        this->shootDirection = DIRECTION::RIGHT;
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left)){
        this->harryTurns_ = this->harry_->mustTurn(1.f,0.f);
        if(this->harryTurns_ == DIRECTION::LEFT){
            this->harry_->flip(harryTurns_);
            harryIsTurning_ = DIRECTION::LEFT;
        }
        else {
            // this->background_->move(1.f,0.f);
        }
        this->shootDirection = DIRECTION::LEFT;
    }   
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Space) && harry_->canAttack()){
        this->spells_.push_back(new Spell(this->textures_[static_cast<int>(texturesTypes::harrySpell)], harry_->getPos().x, harry_->getPos().y, static_cast<float>(this->shootDirection), 0.f, 10.f));
    }

}

void Game::updateSpell(){
    auto counter = 0;
    for (auto *spell : this->spells_){
        spell->update();
        if((spell->getBounds().top + spell->getBounds().height <= 0.f) || (spell->getBounds().top >= this->screenHeight) ||
           (spell->getBounds().left + spell->getBounds().width <= 0.f) || (spell->getBounds().left >= this->screenWidth)){
            delete this->spells_.at(counter);
            this->spells_.erase(this->spells_.begin() + counter);
            --counter;
        }
        ++counter;
    }
}


// void Game::render(){
//     this->window_->clear(sf::Color(50, 200, 50));
    //  this->background_->render(this->window_);
    //  this->harry_->render(*this->window_);
     // Stuff for draw
     for (auto *spell : this->spells_){
         spell->render(this->window_);     }
     this->deathEater_->render(this->window_);

     this->window_->display();
// }


Game::~Game(){
    // delete this->window_;
    // delete this->background_;
    // delete this->harry_;
    for (auto *texture : this->textures_){
        delete texture;
    }
    for (auto *spell : this->spells_){
        delete spell;
    }
}