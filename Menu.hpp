//
//  Menu.hpp
//  SFML
//
//  Created by Hailey Le on 12/3/19.
//  Copyright © 2019 Phuong Thao Le. All rights reserved.
//

#ifndef Menu_hpp
#define Menu_hpp

#include "Commons.hpp"
#include <string>
class Menu
{
public:
    Menu(String main, String sub);
    void drawMenu(RenderWindow &window);
    bool doMenu(Menu menu, RenderWindow &window);

private:
    Font MainFont;
    Text MainText;
    Text SecondText;
};

#endif /* Menu_hpp */
