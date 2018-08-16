//
//  game_Input.hpp
//  clarksouls
//
//  Created by Clark Burton Chambers on 2/10/16.
//  Copyright © 2016 Trash Games. All rights reserved.
//

#ifndef GameInput_hpp
#define GameInput_hpp

#include <stdio.h>
#include "TrashGlobals.h"

typedef struct {
    bool IsDown;
    bool IsPressed;
    bool WasDown;
} game_button_state;

typedef struct{
    union
    {
        game_button_state Buttons[8];
        struct{
            game_button_state Up;
            game_button_state Down;
            game_button_state Left;
            game_button_state Right;
            game_button_state ActionUp;
            game_button_state ActionDown;
            game_button_state ActionLeft;
            game_button_state ActionRight;
        };
    };
} game_controller_input;

typedef enum  {
    //DPad Buttons
            UP, DOWN, LEFT, RIGHT,
    //Action buttons. On a standard Xbox xontroller, hhis would be, from the left to right, Y, A, X, B
            ACTION_UP, ACTION_DOWN, ACTION_LEFT, ACTION_RIGHT
} button_actions;

//Casey
class game_Input {
public:
    //Members
    game_controller_input ControllerInput;
    
    //Constructors and Destructors
    //Init to 0!
    game_Input();
    ~game_Input();

    game_button_state GetControllerButtonState(button_actions action);
};

#endif /* GameInput_hpp */
