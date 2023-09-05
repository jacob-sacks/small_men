#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <iostream>

#ifndef Spell_h
#define Spell_h

class Spell{
    private:
        sf::Sprite shape_;
        sf::Texture* texture_;
        sf::Vector2f direction_;
        float movementSpeed_;
    public:
        Spell();
        Spell(sf::Texture* texture, float originX, float originY, float dirX, float dirY, float movementSpeed);
        ~Spell();
        const sf::FloatRect getBounds() const;
        void update();
        void render(sf::RenderTarget* target);

};



#endif 