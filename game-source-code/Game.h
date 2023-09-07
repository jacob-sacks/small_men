#include <SFML/Audio.hpp>
// #include <SFML/Graphics.hpp>
// #include <SFML/System.hpp>
#include <map>
#include <vector>
// #include "HarryPotter.h"
#include "Spell.h"
#include "DeathEater.h"
#include "Background.h"

// #ifndef Game_h
// #define Game_h

enum class texturesTypes{harrySpell};


class Game{
    private:
        // sf::RenderWindow* window_;
        // std::vector<sf::Texture*> textures_;
        // HarryPotter* harry_;
        DeathEater* deathEater_;
        Background* background_;
        std::vector<Spell*> spells_;
        DIRECTION shootDirection;
        DIRECTION harryTurns_;
        DIRECTION harryIsTurning_;
        const unsigned int screenHeight = 650;
        const unsigned int screenWidth = 1100;
        void turnTransition();
        // void initWindow();
        void initTextures();
        //add harry potter initialisation in initVars
        void initVars();
        // void initHarryPotter(); 
        void initBackground();
    public:
        // Game();
        // ~Game();
        // void run();
        void updatePollEvents();
        void updateInput();
        void update();
        // void render();
        void updateSpell();
};

// #endif 