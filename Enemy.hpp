//
//  Enemy.hpp
//  SFML
//
//  Created by Hailey Le on 12/1/19.
//  Copyright © 2019 Phuong Thao Le. All rights reserved.
//

#ifndef Enemy_hpp
#define Enemy_hpp

#include "Commons.hpp"
#include "Bullet.hpp"
#include "Animation.hpp"
#define ENEMYLIMIT 10

using namespace std;

int getRandomNum(int);
enum reasonForKill{OutofWindow, Shot};

class Difficulty
{
private:
    unsigned int numEnemyWave = 0;
    unsigned int currentDiff = 0;
    unsigned int currentSpeed = 0;
public:
    Difficulty();
    ~Difficulty();
    void updateDiff();
    int getDiff();
    int getSpeed();
};

class Enemy
{
private:
    Difficulty diff;
    Texture etexture;
    Sprite esprite;
public:
    Enemy();
    ~Enemy();
    void update();
    void drawEnemy(RenderWindow &window);
    Sprite* getBody();
    Vector2f getPosition();
    FloatRect getBound();

};

class SystemOfEnemy
{
private:
    bool isCollision(FloatRect, Vector2f);
    void createEnemy(unsigned int);
    void deleteEnemy(Enemy*, unsigned int, reasonForKill, RenderWindow*);

    vector<Enemy*> eList;
    vector<Bullet>* bList = nullptr;
    Gestion animation;
    unsigned int* pBulletCount = nullptr;
    int numEnemy = 0;
    unsigned int killCount = 0;
public:
    SystemOfEnemy(vector<Bullet>* bList, unsigned int* bCount, RenderWindow *window);
    ~SystemOfEnemy();
    void update(RenderWindow* window);
    void resetEnemy();
    int getNumEnemy();
    void drawEnemies(RenderWindow &window);
    unsigned int* getKillNum();
    vector<Enemy*>* getEnemyList();
};
#endif /* Enemy_hpp */
