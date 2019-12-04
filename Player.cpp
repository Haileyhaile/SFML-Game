//
//  Player.cpp
//  SFML
//
//  Created by Hailey Le on 12/1/19.
//  Copyright © 2019 Phuong Thao Le. All rights reserved.
//

#include "Player.hpp"

//Constructor
Player::Player(int m)
{
    max = m;
    Pshape.setPosition(380.0f, 510.0f);
    Pshape.setScale(0.06f, 0.06f);
    if(Ptexture.loadFromFile("/Users/phuongthaolee/Projects/Resources/SpaceShuttles.png"))
    {
        Pshape.setTexture(Ptexture);
    }
    else
    {
        std::cout << "Can't load texture" << std::endl;
        Pshape.setColor(Color::Yellow);
        Pshape.setScale(0.05f,0.05f);
    }
    
}

//Destructor
  Player::~Player()
{
    
}

// Function: getPosition
// Return: Player's space ship position
Vector2f Player::getPosition()
{
    return Vector2f(Pshape.getPosition().x, Pshape.getPosition().y);
}

// Function: getBound
// Return: Ship's global bounds
FloatRect Player::getBound()
{
    return Pshape.getGlobalBounds();
}


void Player::moveLeft()
{
    outOfScreen limit = isOut();
    if(!limit.left)
    {
        if(current == 0 || current < max)
        {
            current++;
        }
        Pshape.move(current - 2 * current, 0.0f);
    }
}

void Player::moveRight()
{
    outOfScreen limit = isOut();
    if(!limit.right)
    {
        if(current == 0 || current < max)
        {
            current++;
        }
        Pshape.move(current, 0.0f);
    }
}

void Player::updateSpeed()
{
    if(speed.getElapsedTime() >= speedDecrease && current > 0)
    {
        current -= 0.5f;
        speed.restart();
    }
}


void Player::drawPlayer(RenderWindow &window)
{
    window.draw(Pshape);
}

outOfScreen Player::isOut()
{
    outOfScreen bounds;
    
    if(Pshape.getPosition().x >= 780.0f || Pshape.getPosition().x <= 0.0f)
    {
        if(Pshape.getPosition().x >= 780.0f)
        {
            Pshape.setPosition(780.0f, Pshape.getPosition().y);
            bounds.right = true;
            return bounds;
        }
        else if(Pshape.getPosition().x <= 0.0f)
        {
            Pshape.setPosition(0.0f, Pshape.getPosition().y);
            return bounds;
        }
    }
    return bounds;
}

// Check if the player is dead
// intersects(Pshape.getGlobalBounds()) ?
// Return true or false (type Bool)
bool Player::Lost(std::vector<Enemy*>* list)
{
    for(int i = 0; i < list->size(); i++)
    {
        if(((*list)[i]->getBound().intersects(Pshape.getGlobalBounds())))
        {
            list->erase(list->begin() + i);
            delete ((*list)[i]);
            return true;
        }
    }
    return false;
}
