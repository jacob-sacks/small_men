#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "Game.h"
#include "HarryPotter.h"
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>

TEST_CASE("Harry Moves 1 Speed Unit Right"){
    auto testHarry = HarryPotter{};
    sf::Vector2f harryStartPos = testHarry.getPos();
    testHarry.move(1.f,0.f);
    sf::Vector2f harryEndPos = testHarry.getPos();
    CHECK(harryStartPos.x == harryEndPos.x - testHarry.getSpeed()); 
    CHECK(harryStartPos.y == harryEndPos.y);
}

TEST_CASE("Harry Moves 1 Speed Unit Left"){
    auto testHarry = HarryPotter{};
    sf::Vector2f harryStartPos = testHarry.getPos();
    testHarry.move(-1.f,0.f);
    sf::Vector2f harryEndPos = testHarry.getPos();
    CHECK(harryStartPos.x == harryEndPos.x + testHarry.getSpeed()); 
    CHECK(harryStartPos.y == harryEndPos.y);
}

TEST_CASE("Harry Moves 1 Speed Unit Up"){
    auto testHarry = HarryPotter{};
    sf::Vector2f harryStartPos = testHarry.getPos();
    testHarry.move(0.f,1.f);
    sf::Vector2f harryEndPos = testHarry.getPos();
    CHECK(harryStartPos.x == harryEndPos.x); 
    CHECK(harryStartPos.y == harryEndPos.y - testHarry.getSpeed());
}

TEST_CASE("Harry Moves 1 Speed Unit Down"){
    auto testHarry = HarryPotter{};
    sf::Vector2f harryStartPos = testHarry.getPos();
    testHarry.move(0.f,-1.f);
    sf::Vector2f harryEndPos = testHarry.getPos();
    CHECK(harryStartPos.x == harryEndPos.x); 
    CHECK(harryStartPos.y == harryEndPos.y + testHarry.getSpeed());
}
