//
// Created by Clark Burton Chambers on 2/29/16.
//

#include "game_PauseState.h"

void game_PauseState::update(sf::Time deltaTime, game_Input *input) {
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space)){
        stateSystem->PopState();
        stateSystem->PushState("testState");
    }
}

void game_PauseState::render(sf::RenderWindow *window) {
}

game_PauseState::game_PauseState(GameStateSystem *system) {
    stateSystem = system;
}