//
//  Score.cpp
//  SFML
//
//  Created by Hailey Le on 12/3/19.
//  Copyright © 2019 Phuong Thao Le. All rights reserved.
//

#include "Score.hpp"

Score::Score(unsigned int *s)
{
    score = s;
    scoreFont.loadFromFile("/Users/phuongthaolee/Projects/Resources/ArimaMaduraiMedium.ttf");
    text.setFont(scoreFont);
    text.setString("ENEMIES KILLED: 0");
    text.setScale(1.0f, 1.0f);
    text.setFillColor(Color::White);
    text.setPosition(1.0f, 1.0f);
}

void Score::updateScore()
{
    if(*score > bestScore)
    {
        bestScore = *score;
    }
    
    text.setString("ENEMIES KILLED: " + std::to_string(*score) + "\nBEST SCORE: " + std::to_string(bestScore));
}

void Score::drawMessage(RenderWindow &window)
{
    window.draw(text);
}
