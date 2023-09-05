#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>

#ifndef DeathEater_H
#define DeathEater_H

class DeathEater{
    private:
        sf::CircleShape shape;
        int type;
        int hp;
        int hpMax;
        int damage;
        int points;
        void initVars();
        void initShape();

    public:
        DeathEater(float posX, float posY);
        void update();
        void render(sf::RenderTarget* target);
        ~DeathEater();

};



#endif