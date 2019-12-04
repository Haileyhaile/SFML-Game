#include "Menu.hpp"


Menu::Menu(string main, string sub)
{
	/* Setting Up Texts and Fonts */
	MainFont.loadFromFile("Resources/#9Slide03ArimaMaduraiMedium.tff");

	MainText.setFont(MainFont);
	MainText.setFillColor(Color::White);
	MainText.setCharacterSize(40);
	MainText.setPosition(150.0, 150.0);
	MainText.setString(main);

	SecondText.setFont(MainFont);
	SecondText.setFillColor(Color::White);
	SecondText.setCharacterSize(30);
	SecondText.setPosition(270.0, 220.0);
	SecondText.setString(sub);
}

void Menu::drawMenu(RenderWindow &window)
{
	window.draw(MainText);
	window.draw(SecondText);
}

bool Menu::doMenu(Menu menu, RenderWindow &window)
{
	while (!Keyboard::isKeyPressed(Keyboard::Return) && !Keyboard::isKeyPressed(Keyboard::Escape))
	{
		Event e;
		window.pollEvent(e);

		if (e.type == Event::Closed)
		{
			window.close();
			break;
		}

		/* Draw menu */
		window.clear(Color::Transparent);
		menu.drawMenu(window);
		window.display();
	}

	if (Keyboard::isKeyPressed(Keyboard::Return))
		return true;
	else
		return false;
}