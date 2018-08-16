//
//  TestSfmlState.cpp
//  clarksouls
//
//  Created by Clark Burton Chambers on 2/8/16.
//  Copyright © 2016 Trash Games. All rights reserved.
//

#include "game_TestSfmlState.h"

// Initiailzes all stuffthings
TestSfmlState::TestSfmlState(GameStateSystem *system){
    stateSystem = system;

    //Passes handle to the window
    if(!tTexture.loadFromFile("src/assets/cute_image.jpg")) {
        //TODO(clark): implement error checking here
    } 
    if(!tFont.loadFromFile("src/assets/OpenSans-Bold.ttf")){
//        TODO(clark): implement error checking here
    }
    
    tSprite.setTexture(tTexture);
    
    tText.setCharacterSize(50);
    tText.setFont(tFont);
    tText.setString("Hello SFML");
    tText.setPosition(800/2.0f, 600/2.0f);
    if(!tMusic.openFromFile("src/assets/nice_music.ogg")) {
//        TODO(clark): Error checking here.
    }
}

void TestSfmlState::update(sf::Time deltaTime, game_Input *input){
    tText.setString(sf::String(std::to_string(deltaTime.asMilliseconds())));

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
    {
        stateSystem->PopState();
        stateSystem->PushState("pauseState");
    }
}

void TestSfmlState::render(sf::RenderWindow *window){
    window->draw(tSprite);
    window->draw(tText);
}

