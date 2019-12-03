//
//  Animation.cpp
//  SFML
//
//  Created by Hailey Le on 12/2/19.
//  Copyright © 2019 Phuong Thao Le. All rights reserved.
//

#include "Animation.hpp"

Animation::Animation(Sprite *b, RenderWindow *w)
{
    curX = 0;
    curY = 0;
    Body = b;
    window = w;
    states = 0;
    tex.loadFromFile("/Users/phuongthaolee/Projects/Resources/Explosion.png");
    Body->setTexture(tex);
    Body->setTextureRect(IntRect(curX, curY, WIDTH, HEIGHT));
}

//int getPosition();

void Animation::drawAni()
{
    window->draw(*Body);
}

bool Animation::updateAni()
{
    if(curX >= MAX_X && curY >= MAX_Y)
    {
        return false;
    }
    if(AniClock.getElapsedTime() >= AniDelay)
    {
        if(curX >= MAX_X)
        {
            AniClock.restart();
            
            curX = 0;
            curY++;
            Body->setTextureRect(IntRect(curX * WIDTH, curY * HEIGHT, HEIGHT, WIDTH));
            return true;
        }
        else
        {
            AniClock.restart();
            curX++;
            Body->setTextureRect(IntRect(curX * WIDTH, curY * HEIGHT, HEIGHT, WIDTH));
            
            return true;
        }
    }
    else
    {
        return true;
    }
}

//bool isChanged();
