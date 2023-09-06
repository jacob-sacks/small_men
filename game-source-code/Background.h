#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <iostream>

#ifndef Background_h
#define Background_h

class Background{

private:
    sf::Sprite background1_;
    sf::Texture texture_;
    const float xScale_ = 0.572917f;
    const float yScale_ = 0.6018519f;
    const float frameWidth_ = 1100.f;

    //Private Functions
    void initTexture();
    void initSprite();
    // const float movementSpeed_ = 5.f;
public:
    Background();
    ~Background();
    void update();
    const sf::Vector2f& getPos() const;
    void render(sf::RenderTarget* targert);
    void move(const float dirX, const float dirY);
};

#endif