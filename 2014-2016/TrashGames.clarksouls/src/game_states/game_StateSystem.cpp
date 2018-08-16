//
//  GameStateSystem.cpp
//  clarksouls
//
//  Created by Clark Burton Chambers on 2/3/16.
//  Copyright © 2016 Trash Games. All rights reserved.
//

// Pointers, Everywhere!
#include<iostream>

#include "game_StateSystem.h"

GameStateSystem::GameStateSystem(){
    currentState = "NULL";
}


// Adds GameState to the list of GameStates in GameStateSystem
void GameStateSystem::AddState(std::string name,GameState *state){
    if(gameStates[name] == nullptr){
        gameStates[name] = state;
    }
}

//Pushes state onto the state stack. This makes it visible for update() and
// render()
void GameStateSystem::PushState(std::string statename){
//    If key does not exist, return false
    stateStack.push(gameStates[statename]);
}

//Pops the top level state off the stack.
void GameStateSystem::PopState(){
    if(stateStack.empty()){
//        Return false, do nothing
//        TODO(clark): THROW EXCEPTION FOR NULL STACK
    } else {
        stateStack.pop();
    }
}

void GameStateSystem::update(sf::Time deltaTime, game_Input *input) {
    //Should be a GameState pointer.
//    TODO(clark): Add support for multiple state rendering
    stateStack.top()->update(deltaTime, input);

}
void GameStateSystem::render(sf::RenderWindow *window) {
    //Renders the top state for now!
//    TODO(clark): Add support for multiple state rendering
    stateStack.top()->render(window);
}

