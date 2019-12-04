//
//  main.cpp
//  SFML
//
//  Created by Hailey Le on 11/21/19.
//  Copyright © 2019 Phuong Thao Le. All rights reserved.
//

//  I used some of the sample codes from https://www.sfml-dev.org/tutorials/2.5/

//  Hi,
//  I coded this game using Xcode on Mac so if you're using other environments
//  Please read my comments to optimize the codes


#include "Commons.hpp"
#include "Player.hpp"
#include "Bullet.hpp"
#include "Score.hpp"
#include "Menu.hpp"
#include "Window.hpp"

int main(void)
{
    srand(time(NULL));
    RenderWindow window(VideoMode( 800, 600 ), "Space Shooter" );
    RenderWindow menu(VideoMode( 800, 600 ), "Space Shooter Menu");
    RenderWindow death(VideoMode( 800, 600 ), "Space Shooter Death");
    //Initialize texts
    //bool lost;
    Font font;
    WindowGestion all(menu, window, death);
    // I code this on my Mac so if you're using Microsoft or other environment
    // you can just use is line of code
    // font.loadFromFile("Resources/#ArimaMaduraiMedium.tff");
    if(!font.loadFromFile("/Users/phuongthaolee/Projects/Resources/ArimaMaduraiMedium.ttf"))
        return -1;
    
    SoundBuffer buffer;
    if(!buffer.loadFromFile("/Users/phuongthaolee/Projects/Resources/Gameloop.wav"))
        return -1;
    Sound sound;
    sound.setBuffer(buffer);
    sound.play();
    
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
    
    if(!all.Show(StartWindow))
    {
        all.~WindowGestion();
        return 0;
    }
    else
    {
        all.Show(PlayWindow);
    }
    
    BulletSystem bullets;
    Player play(25);
    SystemOfEnemy enemy(bullets.getList(), bullets.getNum(), &window);
    Score playerScore(enemy.getKillNum());
    
        while (window.isOpen( ))
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
            enemy.update(&window);
            playerScore.updateScore();

                // draw objects here
            window.clear(Color::Transparent);
            window.draw(background);
            bullets.drawBullet(window);
            play.drawPlayer(window);
            enemy.drawEnemies(window);
            playerScore.drawMessage(window);
            
            //Displaying on screen
            window.display();
            
            if (play.Lost(enemy.getEnemyList()))
            {
                if(all.Show(DeathScreenWindow))
                {
                enemy.resetEnemy();
                bullets.clearBullets();
                all.Show(PlayWindow);
                sound.play();
                //lost = true;
                }
                else
                {
                enemy.resetEnemy();
                bullets.clearBullets();
                all.~WindowGestion();
                return 0;
                }
            }
        }
        return 0;
}
