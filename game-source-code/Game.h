#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <map>
#include <vector>
#include "HarryPotter.h"
#include "Spell.h"
#include "DeathEater.h"

#ifndef Game_h
#define Game_h
enum texturesTypes{harrySpell};

class Game{
    private:
        sf::RenderWindow* window_;
        std::vector<sf::Texture*> textures_;
        HarryPotter* harry_;
        DeathEater* deathEater_;
        std::vector<Spell*> spells_;
        const unsigned int screenHeight = 600;
        const unsigned int screenWidth = 800;
        void initWindow();
        void initTextures();
        void initHarryPotter(); 
    public:
        Game();
        ~Game();
        void run();
        void updatePollEvents();
        void updateInput();
        void update();
        void render();
        void updateSpell();
};

#endif 