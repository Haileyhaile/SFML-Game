//
//  Animation.hpp
//  SFML
//
//  Created by Hailey Le on 12/2/19.
//  Copyright © 2019 Phuong Thao Le. All rights reserved.
//

#ifndef Animation_hpp
#define Animation_hpp

#define MAX_X 4
#define MAX_Y 4
#define WIDTH 64
#define HEIGHT 64

#include "Commons.hpp"

class Animation
{
private:
    Clock AniClock;
    Sprite* Body = nullptr;
    Texture tex;
    unsigned int curX;
    unsigned int curY;
    unsigned int states;
    const Time AniDelay = milliseconds(55);
    RenderWindow *window = nullptr;
public:
    Animation(Sprite *b, RenderWindow *w);
    //Vector2f getPosition();
    void drawAni();
    bool updateAni();
    //bool isChanged();
    
};

class Gestion
{
private:
    std::vector<Animation*> Animated;
    RenderWindow *window = nullptr;
public:
    Gestion(RenderWindow *w = nullptr);
    void clearAnimation();
    void updateAnimation();
    void addAnimation(Sprite*);
    void drawAnimation();
};

#endif /* Animation_hpp */
