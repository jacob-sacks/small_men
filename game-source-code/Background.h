#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <iostream>

#ifndef Background_h
#define Background_h

class Background{

private:
    sf::Sprite background1_;
    sf::Sprite background2_;
    sf::Sprite background3_;
    sf::Texture texture_;
    const float xScale_ = 0.625f;
    const float yScale_ = 0.6018519f;
    const float frameWidth_ = 1200.f;

    //Private Functions
    void initTexture();
    void initSprite();
    const float speed_ = 5.f;
public:
    Background();
    ~Background();
    void update();
    void move(const float dirX, const float dirY);
    void turnHarry(const float dirX, const float dirY);
    void teleport(sf::Sprite* background);
    const sf::Vector2f& getPos() const;
    const float getSpeed();
    void render(sf::RenderTarget* targert);
   
};

#endif