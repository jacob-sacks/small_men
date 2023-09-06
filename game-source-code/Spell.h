#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <iostream>

#ifndef Spell_h
#define Spell_h

class Spell{
    private:
        sf::Sprite spell_;
        sf::Texture* texture_;
        sf::Vector2f direction_;
        const float speed_ = 25.f;
        void initSpell(float originX, float originY, float dirX, float dirY);
    public:
        Spell();
        Spell(sf::Texture* texture, float originX, float originY, float dirX, float dirY);
        ~Spell();
        const sf::FloatRect getBounds() const;
        void update();
        void render(sf::RenderTarget* target);
};



#endif 