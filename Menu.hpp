#ifndef MENUS_H
#define MENUS_H

#include <SFML/Graphics.hpp>
#include <string>
using namespace std;
using namespace sf;

class Menu
{
public:
	Menu(string main, string sub);
	void drawMenu(RenderWindow &window);
	bool doMenu(Menu menu, RenderWindow &window);

private:
	Font MainFont;
	Text MainText;
	Text SecondText;
};

#endif
