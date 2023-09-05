#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <map>
#include <vector>
#include "HarryPotter.h"
#include "Spell.h"

#ifndef Game_h
#define Game_h

class Game{
    private:
        sf::RenderWindow* window;
        std::map<std::string, sf::Texture*> textures;
        void initWindow();
        void initTextures();
        HarryPotter* harry;
        void initHarryPotter();
        std::vector<Spell*> spellsVec; 
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