//
//  GameStateSystem.hpp
//  clarksouls
//
//  Created by Clark Burton Chambers on 2/3/16.
//  Copyright © 2016 Trash Games. All rights reserved.
//

#ifndef GameStateSystem_hpp
#define GameStateSystem_hpp

#include <stdio.h>
#include "TrashGlobals.h"
#include "game_State.h"

class GameStateSystem
{
private:
    std::map<std::string, GameState*> gameStates;
    std::stack<GameState*> stateStack;
    std::string currentState;
public:
    GameStateSystem();
    void AddState(std::string name, GameState *state);
    void PushState(std::string name);
    void PopState();
    void update(sf::Time deltaTime, game_Input *input);
    void render(sf::RenderWindow *window);

};

#endif /* GameStateSystem_hpp */
