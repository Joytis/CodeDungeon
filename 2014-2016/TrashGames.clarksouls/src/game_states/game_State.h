//
//  GameState.hpp
//  clarksouls
//
//  Created by Clark Burton Chambers on 2/3/16.
//  Copyright © 2016 Trash Games. All rights reserved.
//

// Abstract classe for game state!

#ifndef GameState_hpp
#define GameState_hpp

#include <stdio.h>
#include <game_Input.h>
#include "TrashGlobals.h"

class GameState
{
public:
    virtual void update(sf::Time deltaTime, game_Input *input) = 0;
    virtual void render(sf::RenderWindow *window) = 0;
    
};

#endif /* GameState_hpp */
