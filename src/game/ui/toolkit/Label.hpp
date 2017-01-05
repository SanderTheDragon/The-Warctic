#ifndef UI_LABEL_HPP_
#define UI_LABEL_HPP_

#include "SDL2/SDL_ttf.h"

#include "game/ui/toolkit/Box.hpp"
#include "game/ui/toolkit/Color.hpp"
#include "misc/Resource.hpp"
#include "misc/utils/String.hpp"

namespace Ui
{
    class Label : public Ui::Box
    {
    protected:
        std::string text;
        uint textSize;
        bool fontFix;
        
        Resource* res;
        
        Ui::Color foreground;
        
    public:
        Label(int x_, int y_, int w_, int h_, Ui::Color bg, Ui::Color fg, std::string msg, uint size, Resource* font_) : Box(x_, y_, w_, h_, bg), foreground(fg), text(msg), textSize(size), res(font_), fontFix(false) { }
        Label(int x_, int y_, int w_, int h_, Ui::Color bg, int bSize, Ui::Color bColor, Ui::Color fg, std::string msg, uint size, Resource* font_) : Box(x_, y_, w_, h_, bg, bSize, bColor), foreground(fg), text(msg), textSize(size), res(font_), fontFix(false) { }
        
        int Draw(SDL_Renderer** renderer)
        {
            int tW, tH;
            
            Resolve(&tW, &tH);
            
            TTF_Font* font = TTF_OpenFontRW(*(res->Get()), 0, textSize);
            SDL_Color color = { (Uint8)foreground.GetRed(), (Uint8)foreground.GetGreen(), (Uint8)foreground.GetBlue(), (Uint8)foreground.GetAlpha() };
            SDL_Surface* surface = TTF_RenderText_Blended(font, text.c_str(), color);
            SDL_Texture* texture = SDL_CreateTextureFromSurface(*renderer, surface);
            
            SDL_Rect rect;
            
            rect.x = x;
            rect.y = y;
            rect.w = w;
            rect.h = h;
            
            if (borderSize <= 0)
            {
                SDL_SetRenderDrawColor(*renderer, (Uint8)background.GetRed(), (Uint8)background.GetGreen(), (Uint8)background.GetBlue(), (Uint8)background.GetAlpha());
                
                SDL_RenderFillRect(*renderer, &rect);
                
                if (fontFix)
                {
                    rect.w = tW;
                    rect.h = tH;
                }
                
                SDL_RenderCopy(*renderer, texture, NULL, &rect);
            }
            else
            {
                rect.w += 2 * borderSize;
                rect.h += 2 * borderSize;
                
                SDL_SetRenderDrawColor(*renderer, (Uint8)border.GetRed(), (Uint8)border.GetGreen(), (Uint8)border.GetBlue(), (Uint8)border.GetAlpha());
                
                SDL_RenderFillRect(*renderer, &rect);
                
                rect.x += borderSize;
                rect.y += borderSize;
                rect.w -= 2 * borderSize;
                rect.h -= 2 * borderSize;
                
                SDL_SetRenderDrawColor(*renderer, (Uint8)background.GetRed(), (Uint8)background.GetGreen(), (Uint8)background.GetBlue(), (Uint8)background.GetAlpha());
                
                SDL_RenderFillRect(*renderer, &rect);
                
                if (fontFix)
                {
                    rect.w = tW;
                    rect.h = tH;
                }
                
                SDL_RenderCopy(*renderer, texture, NULL, &rect);
            }
                
            SDL_SetRenderDrawColor(*renderer, 0, 0, 0, 255);
            
            TTF_CloseFont(font);
            SDL_FreeSurface(surface);
            SDL_DestroyTexture(texture);
            
            return ERR_OK;
        }
        
        int Resolve() { int i; return Resolve(&i, &i); }
        int Resolve(int* tW, int* tH)
        {
            TTF_Font* font = TTF_OpenFontRW(*(res->Get()), 0, textSize);
            
            int itW, itH;
            
            TTF_SizeText(font, text.c_str(), &itW, &itH);
            
            if (w < 0)
                SetW(itW);

            if (h < 0)
                SetH(itH);
            
            *tW = itW;
            *tH = itH;
            
            TTF_CloseFont(font);
            
            return ERR_OK;
        }
        
        static uint Type() { return UI_LABEL; }
        uint Type_() { Ui::Label::Type(); }
        
        //Get/set text
        void SetText(std::string msg) { text = msg; }
        std::string GetText() { return text; }
        
        //Get/set color
        void SetForeground(Ui::Color color) { foreground = color; }
        void SetForeground(ushort r, ushort g, ushort b, ushort a) { foreground.SetColor(r, g, b, a); }
        Ui::Color GetForeground() { return foreground; }
        Ui::Color* GetForegroundPointer() { return &foreground; }
        
        //Get/set font rect fixer, so the text won't get stretched
        void SetFontFix(bool fix) { fontFix = fix; }
        bool GetFontFix() { return fontFix; }
        
        virtual ~Label() { }
    };
};

#endif
