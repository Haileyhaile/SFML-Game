//
//  Window.hpp
//  SFML
//
//  Created by Hailey Le on 12/3/19.
//  Copyright © 2019 Phuong Thao Le. All rights reserved.
//

#ifndef Window_hpp
#define Window_hpp

#include "Commons.hpp"
#include "Menu.hpp"
#include <string>

enum WindowType
{
    StartWindow,
    PlayWindow,
    DeathScreenWindow
};

class WindowGestion

{
public:
    WindowGestion(RenderWindow &startMenu, RenderWindow &game, RenderWindow &deathWindow);
    bool Show(WindowType type);
    RenderWindow* getWindow(WindowType type);
    ~WindowGestion();

private:
    RenderWindow *StartMenu = nullptr;
    RenderWindow *Game = nullptr;
    RenderWindow *DeathWindow = nullptr;
};

#endif /* Window_hpp */
