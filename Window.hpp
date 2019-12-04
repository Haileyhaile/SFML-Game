#ifndef HEADERS_WINDOW
#define HEADERS_WINDOW

#include <SFML/Graphics.hpp>
#include <iostream>

using namespace sf;

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

#endif
