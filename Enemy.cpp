//
//  Enemy.cpp
//  SFML
//
//  Created by Hailey Le on 12/1/19.
//  Copyright © 2019 Phuong Thao Le. All rights reserved.
//

#include "Enemy.hpp"
unsigned int numWave = 0;

int getRandomNum(int max)
{
    //gets a random number no greater than the max
    return rand() % max;
}

/* ------------------------ ENEMY CLASS ------------------------ */

Enemy::Enemy()
{
    //sets image of enemies to Enemy.png by loading the image to etexture,
    //then seting the texture of the enemy sprite to etexture
    //Please use this line if you're not using Xcode on MacOS
    // etexture.loadFromFile("Resources/Enemy.png");
    if (etexture.loadFromFile("/Users/phuongthaolee/Projects/Resources/Enemy.png"))
        esprite.setTexture(etexture);
    //error checking for if image isn't found -> uses red square instead
    
    else
    {
        esprite.setColor(Color::Red);
        esprite.setScale(0.25, 0.25);
        cout << "Can't open Enemy texture, using default values." << endl;
    }
    //sets position of enemy sprite
    esprite.setScale(0.25, 0.25);
    esprite.setPosition(Vector2f(getRandomNum(800), 50.0));
}

Enemy::~Enemy()
{

}

void Enemy::update()
{
    //updates difficulty level of the game/speed of the enemies
    diff.updateDiff();
    esprite.move(0.0, diff.getSpeed());
}

FloatRect Enemy::getBound()
{
    //returns bounds of the game window
    return esprite.getGlobalBounds();
}

Vector2f Enemy::getPosition()
{
    //returns the position of the enemy sprite
    return esprite.getPosition();
}

void Enemy::drawEnemy(RenderWindow &window)
{
    //draws the enemy in the window
    window.draw(esprite);
}

Sprite* Enemy::getBody()
{
    //returns the enemy sprite
    return &esprite;
}

/* ------------------------ DIFFICULTY CLASS ------------------------ */

Difficulty::Difficulty()
{
    //if wave num is > than zero, wave of enemies is subtracted
    if (numWave > 0)
        numEnemyWave = numWave - 1;
    else
        numEnemyWave = numWave;
    currentSpeed += 2;
}

Difficulty::~Difficulty()
{

}

void Difficulty::updateDiff()
{
    //if wave of enemies is greater than 0
    if (numWave > numEnemyWave)
    {
        //increase wave number by one
        numEnemyWave++;
        //if wave num is less than 3, difficulty increases but not speed
        if (numEnemyWave < 3)
        {
            currentDiff++;
            currentSpeed += 0;
        }
        //if wave num is between 3 and 6, difficulty increases and speed increases by 1
        else if (numEnemyWave > 3 && numEnemyWave < 6)
        {
            currentDiff++;
            currentSpeed += 1;
        }
        //else, speed increases by 3
        else
        {
            currentSpeed += 3;
        }
    }
}

int Difficulty::getDiff()
{
    //returns the current difficulty
    return currentDiff;
}

int Difficulty::getSpeed()
{
    //returns the current speed
    return currentSpeed;
}

/* ------------------------ SYSTEM OF ENEMY CLASS ------------------------ */

SystemOfEnemy::SystemOfEnemy(vector<Bullet>* bulletList, unsigned int* bulletCount, RenderWindow *window)
{
    //initilizes the bullet list and bullet count of the class
    bList = bulletList;
    pBulletCount = bulletCount;

    //gesion = management??
    Gestion a(window);
    animation = a;
}

SystemOfEnemy::~SystemOfEnemy()
{
    
}

bool SystemOfEnemy::isCollision(FloatRect a, Vector2f b)
{
    if(a.contains(b))
        return true;
    else
        return false;
}

void SystemOfEnemy::update(RenderWindow* window)
{
    //loop checks if enemy is out of the window or was shot
    //if enemy was shot -> launch death animation/explosion
    //else enemy leaves the window and is deleted
    for (unsigned int i = 0; i < eList.size(); i++)
    {
        for (unsigned j = 0; j < bList->size(); j++)
        {
            if (isCollision(eList[i]->getBound(), (*bList)[j].getPosition()))
            {
                killCount++;
                deleteEnemy(eList[i], i, Shot, window);
                numEnemy = eList.size();

                bList->erase(bList->begin() + j);
                *pBulletCount = bList->size();

                return;
            }
        }
    }
    for (int i = 0; i < eList.size(); i++)
    {
        eList[i]->update();
        
        if (eList[i]->getPosition().y >= 600)
        {
            deleteEnemy(eList[i], i, OutofWindow, window);
            numEnemy = eList.size();
            return;
        }
    }
    //if there are no enemies are left
    //-> create new ones according to the wave number
    if (numEnemy <= 0)
    {
        numWave++;
        if (numWave * 2 > ENEMYLIMIT)
            createEnemy(ENEMYLIMIT);
        else
            createEnemy(numWave * 2);
    }
    animation.updateAnimation();
}

void SystemOfEnemy::createEnemy(unsigned int num)
{
    //create new enemies
    for (int i = 0; i < num; i++)
    {
        Enemy* e = new(Enemy);
        eList.push_back(e);
    }
}

void SystemOfEnemy::deleteEnemy(Enemy* e, unsigned int position, reasonForKill reason, RenderWindow* window)
{
    //if enemy exits window -> deletes enemy once it leaves screen
    if (reason == OutofWindow)
    {
        eList.erase(eList.begin() + position);
        delete(e);
    }
    //if enemy was shot
    else
    {
        //--- addAnimation DIDN'T HAVE PARAMETER!! ---
        animation.addAnimation(e->getBody());
        eList.erase(eList.begin() + position);
    }
}

void SystemOfEnemy::drawEnemies(RenderWindow &window)
{
    //draws the enemies to the window
    for (int i = 0; i < eList.size(); i++)
    {
        eList[i]->drawEnemy(window);
        numEnemy++;
    }
    animation.drawAnimation();
}

void SystemOfEnemy::resetEnemy()
{
    //resets variables and clears animations
    killCount = 0;
    numWave = 0;
    numEnemy = 0;

    animation.clearAnimation();
    eList.clear();
}

int SystemOfEnemy::getNumEnemy()
{
    //return number of enemies
    return numEnemy;
}

unsigned int* SystemOfEnemy::getKillNum()
{
    //returns kill count
    return &killCount;
}

vector<Enemy*>* SystemOfEnemy::getEnemyList()
{
    //returns enemy list
    return &eList;
}
