//
//  Window.cpp
//  SFML
//
//  Created by Hailey Le on 12/3/19.
//  Copyright © 2019 Phuong Thao Le. All rights reserved.
//

#include "Window.hpp"
WindowGestion::WindowGestion(RenderWindow &startMenu, RenderWindow &game, RenderWindow &deathWindow)
{
    StartMenu = &startMenu;
    Game = &game;
    DeathWindow = &deathWindow;

    StartMenu->setFramerateLimit(60);

    Game->setFramerateLimit(60);
    Game->setVisible(false); // This window isn't show fisrt
    Game->setActive(false); // So inactive too

    DeathWindow->setFramerateLimit(60);
    DeathWindow->setVisible(false); // Same thing for the Death Window
    DeathWindow->setActive(false);
}

bool WindowGestion::Show(WindowType type)
{
   
    Font font;
    
    // I code this on my Mac so if you're using Microsoft or other environment
    // you can just use is line of code
    // font.loadFromFile("Resources/#9Slide03ArimaMaduraiMedium.tff");
    font.loadFromFile("/Users/phuongthaolee/Projects/Resources/ArimaMaduraiMedium.ttf");
    switch (type)
    {
    case StartWindow:
    {
        Game->setVisible(false);
        Game->setActive(false);

        DeathWindow->setVisible(false);
        DeathWindow->setActive(false);

        StartMenu->setVisible(true);
        StartMenu->setActive(true);

        Text Maintxt, Subtxt;
        String main = "WELCOME TO SPACE SHOOTER";
        String sub = "Press Return to Start the Game or Esc to Exit.";

        Maintxt.setFont(font);
        Maintxt.setFillColor(Color::White);
        Maintxt.setCharacterSize(40);
        Maintxt.setPosition(150.0, 150.0);
        Maintxt.setString(main);

        Subtxt.setFont(font);
        Subtxt.setFillColor(Color::White);
        Subtxt.setCharacterSize(30);
        Subtxt.setPosition(270.0, 220.0);
        Subtxt.setString(sub);
        
        Menu menu("WELCOME TO SPACE SHOOTER", "Press Return to play\nPress Escape to quit.");
        
        if (menu.doMenu(menu, *StartMenu))
            return true;
        else
            return false;
    }

    case PlayWindow:
    {
        StartMenu->setVisible(false);
        StartMenu->setActive(false);

        DeathWindow->setVisible(false);
        DeathWindow->setActive(false);

        Game->setVisible(true);
        Game->setActive(true);

        return true;
    }

    case DeathScreenWindow:
    {
        Game->setVisible(false);
        Game->setActive(false);

        DeathWindow->setVisible(true);
        DeathWindow->setActive(true);

        Text Maintxt, Subtxt;
        String main = "WELCOME TO SPACE SHOOTER";
        String sub = "Press Return to Start the Game or Esc to Exit.";

        Maintxt.setFont(font);
        Maintxt.setFillColor(Color::White);
        Maintxt.setCharacterSize(40);
        Maintxt.setPosition(150.0, 150.0);
        Maintxt.setString(main);

        Subtxt.setFont(font);
        Subtxt.setFillColor(Color::White);
        Subtxt.setCharacterSize(30);
        Subtxt.setPosition(270.0, 220.0);
        Subtxt.setString(sub);
        
        Menu menu("YOU LOSE!", "Press Return to play\nPress Escape to quit.");

        if (menu.doMenu(menu, *DeathWindow))
            return true;
        else
            return false;
    }

    default:
        return true;
    }
}

RenderWindow* WindowGestion::getWindow(WindowType type)
{
    switch (type)
    {
    case StartWindow:
        return StartMenu;

    case PlayWindow:
        return Game;

    case DeathScreenWindow:
        return DeathWindow;

    default:
        return NULL;
    }
}

WindowGestion::~WindowGestion()
{
    if (StartMenu->isOpen())
    {
        StartMenu->close();
        StartMenu->~RenderWindow();
    }
    else
    {
        StartMenu->~RenderWindow();
    }

    if (Game->isOpen())
    {
        Game->close();
        Game->~RenderWindow();
    }
    else
    {
        Game->~RenderWindow();
    }

    if (DeathWindow->isOpen())
    {
        DeathWindow->close();
        DeathWindow->~RenderWindow();
    }
    else
    {
        DeathWindow->~RenderWindow();
    }
}
