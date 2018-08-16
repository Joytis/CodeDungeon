
//
// Disclamer:
// ----------
//
// This code will work only if you selected window, graphics and audio.
//
// Note that the "Run Script" build phase will copy the required frameworks
// or dylibs to your application bundle so you can execute it on any OS X
// computer.
//
// Your resource files (images, sounds, fonts, ...) are also copied to your
// application bundle. To get the path to these resource, use the helper
// method resourcePath() from ResourcePath.hpp
//


#include "TrashGlobals.h"
#include "game_State.h"
#include "game_StateSystem.h"
#include "game_TestSfmlState.h"
#include "game_Input.h"

#include <mutex>
#include <thread>
#include <TrashGlobals.h>
#include <game_states/game_PauseState.h>

void thread_updateInput();


int main()
{
    // Create the main window
    sf::RenderWindow *window;
    window = new sf::RenderWindow(sf::VideoMode(800, 600), "ClarkSouls");

    // Set the Icon
    sf::Image icon;
    if (!icon.loadFromFile("src/assets/icon.png")) {
        return EXIT_FAILURE;
    }
    window->setIcon(icon.getSize().x, icon.getSize().y, icon.getPixelsPtr());

    //Initialize State System
    GameStateSystem *stateSystem;
    TestSfmlState *tState = new TestSfmlState(stateSystem);
    game_PauseState *pState = new game_PauseState(stateSystem);
    //Adding a state only adds it to the dictionary of states
    //In the GameStateSystem object. putting it into scope requires
    //pushing it down onto the stack.
    stateSystem->AddState("testState", tState);
    stateSystem->AddState("pauseState", pState);
    //Push the test state onto the stack to give system view of it.
    stateSystem->PushState("testState");
    
    //Manually updates Joystick States
    sf::Joystick::update();
    
    // INITIALIZE INPUT
    std::thread inputThread;
    std::mutex inputMutex;
    game_Input *input = new game_Input();
    
    // Initialize Game Clock
    sf::Clock gameClock;
    
    
    // Start the game loop
    while (window->isOpen())
    {
        // Process events
        sf::Event event;
        while (window->pollEvent(event))
        {
            // Close window: exit
            if (event.type == sf::Event::Closed) {
                window->close();
            }
            
            // Escape pressed: exit
            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape) {
                window->close();
            }
        }

        {
            // Clear screen
            window->clear();
            
            // Render Current GameState;
            stateSystem->update(gameClock.restart(), input);
            stateSystem->render(window);

            // Update the window
            window->display();
        }
    }

    return EXIT_SUCCESS;
}


//CONCERNING BUTTONS:
//        For a standard XBox Controller, buttons are numbered as follows:
//        0: A
//        1: B
//        2: X
//        3: Y
//        4: LB
//        5: RB
//        6: Left Stick Press
//        7: Right Stick Press
//        9: Select (left center button)
//        10: XBox Button
//        11: DPad Up
//        12: DPad Down
//        13: DPad Left
//        14: DPad Right














