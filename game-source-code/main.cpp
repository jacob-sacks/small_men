/** \file pong-main.cpp
    \brief Contains the main function

    NB:to document global objects (functions, typedefs, enum, macros, etc), you must document the file in which they are defined. That is,
    you must provide this file comment block.
 */


////////////////////////////////////////////////////////////
// Headers
////////////////////////////////////////////////////////////
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include<time.h>
#include "Game.h"
#include "HarryPotter.h"
#include "Spell.h"
#include "DeathEater.h"
#include "Background.h"



int main()
{
    srand(time(static_cast<unsigned>(0)));
	Game g; 
	g.run();
    Background b;


	
    return EXIT_SUCCESS;
}
