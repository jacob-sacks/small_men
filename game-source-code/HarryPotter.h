
// #include <SFML/Audio.hpp>
// #include <SFML/Graphics.hpp>
// #include <SFML/System.hpp>

// #ifndef HarryPotter_H
// #define HarryPotter_H


// enum class DIRECTION{LEFT = -1, NO_TURN, RIGHT};
// class HarryPotter
// {
// private:
//     sf::Sprite harryPotter_;
//     sf::Texture texture;

    //Private Functions
    // void initTexture();
    // void initHarryPotter();
    // const float speed_ = 1.f;
    // const float attackCoolDownMax_ = 8.f;
    const float defaultLeftPos_ = 200.f;
    const float defaultRightPos_ = 900.f;
    // const float startWidth_ = 200.f;
    // const float startHeight_ = 300.f;
    // float attackCoolDown_ = attackCoolDownMax_;

// public:
//     HarryPotter();
//     ~HarryPotter();
    // void update();
    // void updateCoolDown();
    // void flip(DIRECTION dir);
    // DIRECTION mustTurn(const float dirX, const float dirY);
    // const sf::Vector2f& getPos() const;
    // void render(sf::RenderTarget& targert);
    // void move(const float dirX, const float dirY);
    // const bool canAttack();
    // void resetCoolDown();
    // const float getStartWidth();
    float getSpeed();
    
// };



// #endif