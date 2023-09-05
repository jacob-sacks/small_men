#include <iostream>
#include <iomanip>
#include "Game.h"
#include "HarryPotter.h"

Game::Game(){
    this->initWindow();
    this->initTextures();
    this->initVars();
}

void Game::initWindow(){
    this->window_ = new sf::RenderWindow(sf::VideoMode(this->screenWidth, this->screenHeight), "Game", sf::Style::Close | sf::Style::Titlebar);
    this->window_->setVerticalSyncEnabled(true);
}

void Game::initTextures(){
    this->textures_.push_back(new sf::Texture());
    this->textures_[static_cast<int>(texturesTypes::harrySpell)]->loadFromFile("resources/harry_spell.png");
}

void Game::initHarryPotter(){
    this->harry_ = new HarryPotter();
    this->deathEater_ = new DeathEater(20.f, 20.f);
}

void Game::initVars()
{
    this->initHarryPotter();
    this->shootDirection = SHOOT_DIRECTION::RIGHT;
}

void Game::run(){
    while(this->window_->isOpen()){
        this->update();
        this->render();
    }
}

void Game::update(){
   this->updatePollEvents();
   this->updateInput();
   this->updateSpell();
   this->harry_->update();
   
}


void Game::updatePollEvents(){
    sf::Event e;
    while (this->window_->pollEvent(e)){
        if(e.Event::type == sf::Event::Closed)
            this->window_->close();
        if(e.Event::KeyPressed && e.Event::key.code == sf::Keyboard::Escape)
            this->window_->close();    
    }
}

void Game::updateInput(){
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up))
        this->harry_->move(0.f,-1.f);
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down))
        this->harry_->move(0.f,1.f);
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right)){
        this->harry_->move(1.f,0.f);
        this->shootDirection = SHOOT_DIRECTION::RIGHT;
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left)){
        this->harry_->move(-1.f,0.f);
        this->shootDirection = SHOOT_DIRECTION::LEFT;
    }   
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Space) && harry_->canAttack()){
        this->spells_.push_back(new Spell(this->textures_[static_cast<int>(texturesTypes::harrySpell)], harry_->getPos().x, harry_->getPos().y, static_cast<float>(this->shootDirection), 0.f, 5.f));
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


void Game::render(){
    this->window_->clear(sf::Color(50, 200, 50));
    this->harry_->render(*this->window_);
    // Stuff for draw
    for (auto *spell : this->spells_){
        spell->render(this->window_);
    }
    this->deathEater_->render(this->window_);

    this->window_->display();
}


Game::~Game(){
    delete this->window_;
    delete this->harry_;
    for (auto *texture : this->textures_){
        delete texture;
    }
    for (auto *spell : this->spells_){
        delete spell;
    }
}