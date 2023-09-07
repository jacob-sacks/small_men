#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "Game.h"
#include "HarryPotter.h"
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>

TEST_CASE("Harry moves 1 speed unit right"){
    auto testHarry = HarryPotter{};
    sf::Vector2f harryStartPos = testHarry.getPos();
    testHarry.move(1.f,0.f);
    sf::Vector2f harryEndPos = testHarry.getPos();
    CHECK(harryStartPos.x == harryEndPos.x - testHarry.getSpeed()); 
    CHECK(harryStartPos.y == harryEndPos.y);
}

TEST_CASE("Harry moves 1 speed unit left"){
    auto testHarry = HarryPotter{};
    sf::Vector2f harryStartPos = testHarry.getPos();
    testHarry.move(-1.f,0.f);
    sf::Vector2f harryEndPos = testHarry.getPos();
    CHECK(harryStartPos.x == harryEndPos.x + testHarry.getSpeed()); 
    CHECK(harryStartPos.y == harryEndPos.y);
}

TEST_CASE("Harry moves 1 speed unit up"){
    auto testHarry = HarryPotter{};
    sf::Vector2f harryStartPos = testHarry.getPos();
    testHarry.move(0.f,1.f);
    sf::Vector2f harryEndPos = testHarry.getPos();
    CHECK(harryStartPos.x == harryEndPos.x); 
    CHECK(harryStartPos.y == harryEndPos.y - testHarry.getSpeed());
}

TEST_CASE("Harry moves 1 speed unit down"){
    auto testHarry = HarryPotter{};
    sf::Vector2f harryStartPos = testHarry.getPos();
    testHarry.move(0.f,-1.f);
    sf::Vector2f harryEndPos = testHarry.getPos();
    CHECK(harryStartPos.x == harryEndPos.x); 
    CHECK(harryStartPos.y == harryEndPos.y + testHarry.getSpeed());
}

TEST_CASE("Harry's Spells can not be shot one after another"){
    auto testHarry = HarryPotter{};
    //Shoot
    testHarry.resetCoolDown();
    testHarry.updateCoolDown();
    CHECK_FALSE(testHarry.canAttack());
}

TEST_CASE("Harry's can fire multiple spells after waiting for cooldown period to expire"){
    const int coolDownWait = 17;
    auto testHarry = HarryPotter{};
    //Shoot
    testHarry.resetCoolDown();
    for(auto counter = 0; counter < coolDownWait; ++counter)
        testHarry.updateCoolDown();
    CHECK(testHarry.canAttack());
}


