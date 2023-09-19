#ifndef COLOR_TYPE_HPP
#define COLOR_TYPE_HPP

enum class ColorType
{
    None = -1, Black, White, ColorNumber = 2
};

class Color{
private:
public:
    static ColorType getReverseColor(ColorType color){
        switch (color){
            using enum ColorType;
        case Black:
            return White;
        case White:
            return Black;
        default:
            return None;
        }
    }
};

#endif