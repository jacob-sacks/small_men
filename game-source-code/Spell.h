#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <iostream>
#include <cmath>

#ifndef Spell_h
#define Spell_h

class Spell{
    private:
        sf::Sprite spell_;
        sf::Texture* texture_;
        float dirX_;
        float dirY_;
        float speed_ = 5.f;
        float phantomSpeed_;
        void initSpell(float originX, float originY, float dirX, float dirY);
    public:
        Spell();
        Spell(sf::Texture* texture, float originX, float originY, float dirX, float dirY);
        ~Spell();
        void setRelativeSpeed(float phantomSpeed);
        const sf::FloatRect getBounds() const;
        void update();
        void render(sf::RenderTarget* target);
        void print();
};



#endif 