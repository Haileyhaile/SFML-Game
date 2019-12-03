//
//  Bullet.hpp
//  SFML
//
//  Created by Hailey Le on 12/1/19.
//  Copyright © 2019 Phuong Thao Le. All rights reserved.
//

#ifndef Bullet_hpp
#define Bullet_hpp

#define BULLET_SPEED 20
#define BULLET_AMOUNT 1000


#include "Commons.hpp"

class Bullet: public Drawable, public Transformable
{
public:
    Bullet(Vector2f playerPosition);
    virtual Vector2f getPosition() const;
    bool update();
private:
    VertexArray bullets;
    virtual void draw(RenderTarget &target, RenderStates states) const;
};

class BulletSystem
{
private:
    std::vector<Bullet> Containter;
    unsigned int count = 0;
public:
    std::vector<Bullet>*getList();
    void drawBullet(RenderWindow &window);
    void addBullet(Vector2f playerPosition);
    void updateCount();
    void clearBullets();
    unsigned int* getNum();
    
};

#endif /* Bullet_hpp */
