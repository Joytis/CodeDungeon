//
//  TestSfmlState.hpp
//  clarksouls
//
//  Created by Clark Burton Chambers on 2/8/16.
//  Copyright © 2016 Trash Games. All rights reserved.
//

#ifndef TestSfmlState_hpp
#define TestSfmlState_hpp

#include "TrashGlobals.h"

#include <stdio.h>

#include "game_State.h"
#include "game_StateSystem.h"

class TestSfmlState : public GameState
{
private:
    GameStateSystem *stateSystem;

    sf::Texture tTexture;
    sf::Sprite tSprite;
    sf::Font tFont;
    sf::Text tText;
    sf::Music tMusic;
public:
    ~TestSfmlState();
    TestSfmlState(GameStateSystem *system);

    virtual void update(sf::Time deltaTime, game_Input *input);
    virtual void render(sf::RenderWindow *window);
};
#endif /* TestSfmlState_hpp */
