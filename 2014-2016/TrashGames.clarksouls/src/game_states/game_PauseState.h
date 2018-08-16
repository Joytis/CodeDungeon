//
// Created by Clark Burton Chambers on 2/29/16.
//

#ifndef CLARKSOULS_GAME_PAUSESTATE_H
#define CLARKSOULS_GAME_PAUSESTATE_H

#include "TrashGlobals.h"
#include "game_State.h"
#include "game_StateSystem.h"

class game_PauseState : public GameState{
private:
    GameStateSystem *stateSystem;
public:
    game_PauseState(GameStateSystem *system);

    virtual void update(sf::Time deltaTime, game_Input *input);
    virtual void render(sf::RenderWindow *window);
};


#endif //CLARKSOULS_GAME_PAUSESTATE_H
