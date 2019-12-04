//
//  Player.hpp
//  SFML
//
//  Created by Hailey Le on 12/1/19.
//  Copyright © 2019 Phuong Thao Le. All rights reserved.
//

#ifndef Player_hpp
#define Player_hpp

#include "Commons.hpp"
#include "Enemy.hpp"
struct outOfScreen
{
    bool left = false;
    bool right = false;
};

class Player
{
public:
    //constructor and destructor
    Player(int);
    ~Player();
    void moveLeft();
    void moveRight();
    void drawPlayer(RenderWindow &window);
    void updateSpeed();
    bool Lost(std::vector<Enemy*>* list);
    Vector2f getPosition();
    FloatRect getBound();
    
    
private:
    float current = 0.0f;
    int max;
    Sprite Pshape;
    Texture Ptexture;
    Clock speed;
    const Time speedDecrease = milliseconds(10);
    
    outOfScreen isOut();
};

#endif /* Player_hpp */
