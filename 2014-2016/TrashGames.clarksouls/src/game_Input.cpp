//
//  game_Input.cpp
//  clarksouls
//
//  Created by Clark Burton Chambers on 2/10/16.
//  Copyright © 2016 Trash Games. All rights reserved.
//

#include <SFML/Graphics.hpp>

#include "game_Input.h"
#include "TrashGlobals.h"

//Lil helper function
//TODO(clark): Maybe add support for sub-frame input. No. Definitely do this.

game_button_state game_Input::GetControllerButtonState(button_actions action){
    switch (action){
        case button_actions::UP:
        {
            return ControllerInput.Up;
        }break;
        case button_actions::DOWN:
        {
            return ControllerInput.Down;
        }break;
        case button_actions::LEFT:
        {
            return ControllerInput.Left;
        }break;
        case button_actions::RIGHT:
        {
            return ControllerInput.Right;
        }break;
        case button_actions::ACTION_UP:
        {
            return ControllerInput.ActionUp;
        }break;
        case button_actions::ACTION_DOWN:
        {
            return ControllerInput.ActionDown;
        }break;
        case button_actions::ACTION_LEFT:
        {
            return ControllerInput.ActionLeft;
        }break;
        case button_actions::ACTION_RIGHT:
        {
            return ControllerInput.ActionRight;
        }break;
            
    }
}


game_Input::game_Input(){
    ControllerInput = {};
}


