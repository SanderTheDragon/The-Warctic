#ifndef UI_COLOR_HPP_
#define UI_COLOR_HPP_

#include <iostream>

namespace Ui
{
    class Color
    {
    private:
        ushort r;
        ushort g;
        ushort b;
        ushort a;
        
    public:
        Color(ushort r_, ushort g_, ushort b_, ushort a_) : r(r_), g(g_), b(b_), a(a_) { }
        
        //Increase/decrease r/g/b/a
        void ShiftRed(short i)   { if (r + i > 255) r = 255; else if (r + i < 0) r = 0; else r += i; }
        void ShiftGreen(short i) { if (g + i > 255) g = 255; else if (g + i < 0) g = 0; else g += i; }
        void ShiftBlue(short i)  { if (b + i > 255) b = 255; else if (b + i < 0) b = 0; else b += i; }
        void ShiftAlpha(short i) { if (a + i > 255) a = 255; else if (a + i < 0) a = 0; else a += i; }
        
        //Increase/decrease r/g/b/a limited
        void ShiftRed(short i, ushort min, ushort max)   { if (r + i > max) r = max; else if (r + i < min) r = min; else r += i; }
        void ShiftGreen(short i, ushort min, ushort max) { if (g + i > max) g = max; else if (g + i < min) g = min; else g += i; }
        void ShiftBlue(short i, ushort min, ushort max)  { if (b + i > max) b = max; else if (b + i < min) b = min; else b += i; }
        void ShiftAlpha(short i, ushort min, ushort max) { if (a + i > max) a = max; else if (a + i < min) a = min; else a += i; }
        
        //Set r/g/b/a
        void SetColor(ushort r_, ushort g_, ushort b_, ushort a_) { SetRed(r_); SetGreen(g_); SetBlue(b_); SetAlpha(a_); }
        void SetRed(ushort r_)   { if (r_ > 255) r = 255; else r = r_; }
        void SetGreen(ushort g_) { if (g_ > 255) g = 255; else g = g_; }
        void SetBlue(ushort b_)  { if (b_ > 255) b = 255; else b = b_; }
        void SetAlpha(ushort a_) { if (a_ > 255) a = 255; else a = a_; }
        
        //Get r/g/b/a
        ushort GetRed()   { return r; }
        ushort GetGreen() { return g; }
        ushort GetBlue()  { return b; }
        ushort GetAlpha() { return a; }
        
        virtual ~Color() { }
    };
};

#endif
