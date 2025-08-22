#pragma once

namespace my_color
{
    // Please note: this is an enum CLASS and not a simple enum. This has more features
    enum class Color 
    { 
        red, 
        green,
        blue
    };
    
    Color& operator++(Color& c)
    {
        switch (c)
        {
            case Color::red:
                return c = Color::green;
            case Color::green:
                return c = Color::blue;
            case Color::blue:
                return c = Color::red;
        }
    }
}