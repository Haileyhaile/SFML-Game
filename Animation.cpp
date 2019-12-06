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
    //Please use this line if you're not using Xcode on MacOS
    // text.loadFromFile("Resources/Explosion.png");
    tex.loadFromFile("/Users/phuongthaolee/Projects/Resources/Explosion.png");
    Body->setTexture(tex);
    Body->setTextureRect(IntRect(curX, curY, WIDTH, HEIGHT));
    Body->setScale(1.0f, 1.0f);
}


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
            //Body->setScale(1.0f, 1.0f);
            return true;
        }
        else
        {
            AniClock.restart();
            curX++;
            Body->setTextureRect(IntRect(curX * WIDTH, curY * HEIGHT, HEIGHT, WIDTH));
            //Body->setScale(1.0f, 1.0f);
            return true;
        }
    }
    else
    {
        return true;
    }
}

Gestion::Gestion(RenderWindow *w)
{
    window = w;
}

void Gestion::clearAnimation()
{
    Animated.clear();
}

void Gestion::updateAnimation()
{
    for(int i = 0; i < Animated.size(); i++)
    {
        if(!Animated[i]->updateAni())
        {
            delete(Animated[i]);
            Animated.erase(Animated.begin() + i);
        }
    }
}

void Gestion::addAnimation(Sprite*body)
{
    Animation *a = new Animation(body, window);
    Animated.push_back(a); //This is cool lol it's like push() but at the back
}

void Gestion::drawAnimation()
{
    for(int i = 0; i < Animated.size(); i++)
    {
        Animated[i]->drawAni();
    }
}
