//
//  Bullet.cpp
//  SFML
//
//  Created by Hailey Le on 12/1/19.
//  Copyright © 2019 Phuong Thao Le. All rights reserved.
//

#include "Bullet.hpp"

Bullet:: Bullet(Vector2f playerPosition)
{
    VertexArray coord(Triangles, 3);
    
    coord[0].position = Vector2f(playerPosition.x + 29.0, playerPosition.y + 29.0);
     coord[1].position = Vector2f(playerPosition.x + 30.0, playerPosition.y + 30.0);
     coord[2].position = Vector2f(playerPosition.x + 28.0, playerPosition.y + 28.0);
    
    coord.resize(3);
    
    for(unsigned int i = 0; i < 2; i++)
    {
        coord[i].color = Color::Yellow;
    }
    
    bullets = coord;
}

Vector2f Bullet::getPosition() const
{
    return bullets[1].position;
}

bool Bullet::update()
{
    for(int i = 0; i< 1 + 1; i++)
    {
        bullets[i] = Vector2f(bullets[i].position.x, bullets[i].position.y - BULLET_SPEED);
        if(bullets[i].position.y <= 0 || bullets[i].position.y >= 600)
            return true;
    }
    return false;
}
void Bullet::draw(RenderTarget &target, RenderStates states) const
{
    states.transform *= getTransform();
    states.texture = NULL;
    
    target.draw(bullets, states);
}

std::vector<Bullet>* BulletSystem::getList()
{
    return &Containter;
}

void BulletSystem::drawBullet(RenderWindow &window)
{
    for(int i = 0; i < Containter.size(); i++)
    {
        window.draw(Containter[i]);
    }
    
}

void BulletSystem::addBullet(Vector2f playerPosition)
{
    if(count < BULLET_AMOUNT)
    {
        Bullet b(playerPosition);
        Containter.push_back(b);
        count++;
    }
    
}

void BulletSystem::updateCount()
{
    for(int i = 0; i < Containter.size(); i ++)
    {
        if(Containter[i].update())
        {
            Containter.erase(Containter.begin() + i);
            count--;
        }
    }
}

void BulletSystem::clearBullets()
{
    Containter.clear();
}

unsigned int* BulletSystem::getNum()
{
    return &count;
}
