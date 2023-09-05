
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
    const float movementSpeed_ = 5.f;
    const float attackCoolDownMax_ = 10.f;
    float attackCoolDown_ = attackCoolDownMax_;

public:
    HarryPotter();
    ~HarryPotter();
    void update();
    void updateCoolDown();
    // void flipHarry(Direction dirr);
    const sf::Vector2f& getPos() const;
    void render(sf::RenderTarget& targert);
    void move(const float dirX, const float dirY);
    const bool canAttack();
    
};



#endif