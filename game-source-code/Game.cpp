#include "Game.h"
#include "HarryPotter.h"

Game::Game()
{
    this->initWindow();
    this->initTextures();
    this->initHarryPotter();
}

void Game::initWindow()
{
    this->window = new sf::RenderWindow(sf::VideoMode(800, 600), "Game", sf::Style::Close | sf::Style::Titlebar);
    //this->window->setFramerateLimit(60);
    this->window->setVerticalSyncEnabled(true);
}

void Game::initTextures(){
    this->textures["harrySpell"] = new sf::Texture();
    this->textures["harrySpell"]->loadFromFile("resources/harry_spell.png");
}

void Game::initHarryPotter()
{
    this->harry = new HarryPotter();
    
}

void Game::run()
{
    while(this->window->isOpen()){
        this->update();
        this->render();
    }
}

void Game::update(){
   this->updatePollEvents();
   this->updateInput();
   this->updateSpell();
   this->harry->update();
}


void Game::updatePollEvents(){
    sf::Event e;
    while (this->window->pollEvent(e)){
        if(e.Event::type == sf::Event::Closed)
            this->window->close();
        if(e.Event::KeyPressed && e.Event::key.code == sf::Keyboard::Escape)
            this->window->close();    
    }
}

void Game::updateInput(){
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up))
        this->harry->move(0.f,-1.f);
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down))
        this->harry->move(0.f,1.f);
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right))
        this->harry->move(1.f,0.f);
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left))
        this->harry->move(-1.f,0.f);   
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Space) && harry->canAttack()){
        this->spellsVec.push_back(new Spell(this->textures["harrySpell"], harry->getPos().x, harry->getPos().y, 1.f, 0.f, 5.f));
    }

}

void Game::updateSpell(){
    auto counter = 0;
    for (auto *spell : this->spellsVec){
        spell->update();
        if(spell->getBounds().top + spell->getBounds().height <= 0.f){
            delete this->spellsVec.at(counter);
            this->spellsVec.erase(this->spellsVec.begin() + counter);
            --counter;
        }
        ++counter;
    }


}


void Game::render()
{
    this->window->clear(sf::Color(50, 200, 50));
    this->harry->render(*this->window);
    // Stuff for draw
    for (auto *spell : this->spellsVec){
        spell->render(this->window);
    }

    this->window->display();
}


Game::~Game()
{
    delete this->window;
    delete this->harry;
    for (auto &texture : this->textures){
        delete texture.second;
    }
    for (auto *spell : this->spellsVec){
        delete spell;
    }
}