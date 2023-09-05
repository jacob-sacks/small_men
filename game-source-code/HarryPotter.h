
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>

#ifndef HarryPotter_H
#define HarryPotter_H


class HarryPotter
{
private:
    sf::Sprite sprite;
    sf::Texture texture;

    //Private Functions
    void initTexture();
    void initSprite();
    void initVars();
    float movementSpeed;

    float attackCoolDown;
    float attackCoolDownMax;

public:
    HarryPotter();
    ~HarryPotter();
    void update();
    void updateCoolDown();
    const sf::Vector2f& getPos() const;
    void render(sf::RenderTarget& targert);
    void move(const float dirX, const float dirY);
    const bool canAttack();
};



#endif