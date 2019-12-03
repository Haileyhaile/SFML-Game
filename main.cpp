//
//  main.cpp
//  SFML
//
//  Created by Hailey Le on 11/21/19.
//  Copyright © 2019 Phuong Thao Le. All rights reserved.
//
//  Hi,
//  I coded this game using Xcode on Mac so if you're using other environments
//  Please read my comments to optimize the codes


#include "Commons.hpp"
#include "Player.hpp"
#include "Bullet.hpp"

int main(void)
{
    srand(time(NULL));
    RenderWindow window(VideoMode( 800, 600 ), "Space Shooter" );
    
    //Initialize texts
    Font font;
    bool lost = true; 
    
    // I code this on my Mac so if you're using Microsoft or other environment
    // you can just use is line of code
    // font.loadFromFile("Resources/#9Slide03ArimaMaduraiMedium.tff");
    font.loadFromFile("/Users/phuongthaolee/Projects/Resources/ArimaMaduraiMedium.ttf");
    
    Texture BackgroundTexture;
    Sprite background;
    Vector2u TextureSize;  //Added to store texture size.
    Vector2u WindowSize;   //Added to store window size.

    
    // I code this on my Mac so if you're using Microsoft or other environment
    // you can just use is line of code
    //  if(!BackgroundTexture.loadFromFile("Resources/Background.png"))
    if(!BackgroundTexture.loadFromFile("/Users/phuongthaolee/Projects/Resources/Background.png"))
    {
      return -1;
    }
    else
    {
      TextureSize = BackgroundTexture.getSize(); //Get size of texture.
      WindowSize = window.getSize();             //Get size of window.

      float ScaleX = (float) WindowSize.x / TextureSize.x;
      float ScaleY = (float) WindowSize.y / TextureSize.y;     //Calculate scale.

      background.setTexture(BackgroundTexture);
      background.setScale(ScaleX, ScaleY);      //Set scale.
    }
    
    Text Maintxt, Subtxt;
	string main = "WELCOME TO SPACE SHOOTER";
	string sub = "Press Return to Start the Game or Esc to Exit.";

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
    
    BulletSystem bullets;
    Player play(2);
    SystemOfEnemy enemy(bullets.getList(), bullets.getNum(), &window);
    
    while (window.isOpen( ) && lost == true)
    {
        Event event;
        
        // handle all events
        while (window.pollEvent(event))
        {
            
            if(event.type == Event::Closed)
            {
                window.close();
            }
        }
//display menu
		window.draw(Maintxt);
		window.draw(Subtxt);
		window.display();
		if (Keyboard::isKeyPressed(Keyboard::Return))
		{
			//Control check
			if (Keyboard::isKeyPressed(Keyboard::Left))
			{
				// left key is pressed: move our character
				play.moveLeft();
			}
			else if (Keyboard::isKeyPressed(Keyboard::Right))
			{
				play.moveRight();
			}
			else if (Keyboard::isKeyPressed(Keyboard::Space))
			{
				bullets.addBullet(play.getPosition());
			}

			// update the game
			play.updateSpeed();
			bullets.updateCount();

			// draw objects here
			window.clear(Color::Transparent);
			window.draw(background);

			bullets.drawBullet(window);
			play.drawPlayer(window);

			window.display();

			if (play.Lost(enemy.getEnemyList()))
			{
				enemy.resetEnemy();
				bullets.clearBullets();
				lost = true;
			}
			/* else
			{
			enemy.resetEnemy();
			bullets.clearBullets();
			//return 0;
			}*/
		}
		else if (Keyboard::isKeyPressed(Keyboard::Escape))
		{
			lost = false;
		}
    
    return 0;
}
