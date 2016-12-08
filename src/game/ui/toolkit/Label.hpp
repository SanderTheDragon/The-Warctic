#ifndef UI_LABEL_HPP_
#define UI_LABEL_HPP_

#include "SDL2/SDL_ttf.h"

#include "game/ui/toolkit/Box.hpp"
#include "game/ui/toolkit/Color.hpp"

namespace Ui
{
    class Label : public Ui::Box
    {
    protected:
        std::string text;
        uint textSize;
        
        Ui::Color foreground;
        
    public:
        Label(int x_, int y_, int w_, int h_, Ui::Color bg, Ui::Color fg, std::string msg, uint size) : Box(x_, y_, w_, h_, bg), foreground(fg), text(msg), textSize(size) { }
        
        void Draw(SDL_Renderer** renderer)
        {
            TTF_Font* font = TTF_OpenFont("./freemono.ttf", textSize); //TODO: get ttf from resource pack
            SDL_Color color = { (Uint8)foreground.GetRed(), (Uint8)foreground.GetGreen(), (Uint8)foreground.GetBlue(), (Uint8)foreground.GetAlpha() };
            SDL_Surface* surface = TTF_RenderText_Solid(font, text.c_str(), color);
            SDL_Texture* texture = SDL_CreateTextureFromSurface(*renderer, surface);
            
            SDL_SetRenderDrawColor(*renderer, background.GetRed(), background.GetGreen(), background.GetBlue(), (Uint8)background.GetAlpha());
            
            SDL_Rect rect;
            
            rect.x = x;
            rect.y = y;
            
            int tW, tH;
            
            TTF_SizeText(font, text.c_str(), &tW, &tH);
            
            if (w < 0)
            {
                rect.w = tW;
                SetW(tW);
            }
            else
                rect.w = w;
            
            if (h < 0)
            {
                rect.h = tH;
                SetH(tH);
            }
            else
                rect.h = h;
            
            SDL_RenderFillRect(*renderer, &rect);            
            SDL_RenderCopy(*renderer, texture, NULL, &rect);
            
            SDL_SetRenderDrawColor(*renderer, 0, 0, 0, 255);
            
            TTF_CloseFont(font);
            SDL_FreeSurface(surface);
            SDL_DestroyTexture(texture);
        }
        
        //Get/set text
        void SetText(std::string msg) { text = msg; }
        std::string GetText() { return text; }
        
        //Get/set color
        void SetForeground(Ui::Color color) { foreground = color; }
        void SetForeground(ushort r, ushort g, ushort b, ushort a) { foreground.SetColor(r, g, b, a); }
        Ui::Color GetForeground() { return foreground; }
        Ui::Color* GetForegroundPointer() { return &foreground; }
        
        virtual ~Label() { }
    };
};

#endif
