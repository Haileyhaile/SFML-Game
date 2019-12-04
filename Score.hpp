//
//  Score.hpp
//  SFML
//
//  Created by Hailey Le on 12/3/19.
//  Copyright © 2019 Phuong Thao Le. All rights reserved.
//

#ifndef Score_hpp
#define Score_hpp

#include "Commons.hpp"
class Score
{
private:
    unsigned int *score = nullptr;
    unsigned int bestScore = 0;
    Font scoreFont;
    Text text;
public:
    Score(unsigned int *s);
    void updateScore();
    void drawMessage(RenderWindow &window);
};

#endif /* Score_hpp */
