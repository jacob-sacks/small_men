#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <map>
#include <vector>
#include <algorithm>
#include "HarryPotter.h"
#include "Spell.h"
#include "DeathEater.h"
#include "Background.h"

#ifndef Game_h
#define Game_h

enum class texturesTypes{harrySpell};


class Game{
    private:
        sf::RenderWindow* window_;
        std::vector<sf::Texture*> textures_;
        HarryPotter* harry_;
        DeathEater* deathEater_;
        Background* background_;
        std::vector<Spell*> spells_;
        DIRECTION shootDirection;
        DIRECTION harryTurns_;
        DIRECTION harryIsTurning_;
        bool isHoldingSpace_;
        const unsigned int screenHeight = 650;
        const unsigned int screenWidth = 1200;
        float phantomXVelocity_;
        float phantomTurnVelocity_;
        void turnTransition();
        void initWindow();
        void initTextures();
        void initVars();
        void initHarryPotter(); 
        void initBackground();
    public:
        Game();
        ~Game();
        void run();
        void updatePollEvents();
        void updateInput();
        void updateSpell();
        void update();
        void render();
};

#endif 