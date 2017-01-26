#ifndef UI_ERRORBOX_HPP_
#define UI_ERRORBOX_HPP_

#include "ui/toolkit/Label.hpp"
#include "ui/toolkit/Color.hpp"
#include "ui/toolkit/Button.hpp"
#include "ui/toolkit/Overlay.hpp"
#include "misc/utils/String.hpp"

namespace Ui
{
    class ErrorBox : public Ui::Overlay
    {
    protected:
        std::string message;
        
    public:
        ErrorBox(std::string msg) : Overlay(64, 96, WINDOW_W() - 64, WINDOW_H() - 96, Ui::Color(126, 0, 0, 255), 2, Ui::Color(255, 0, 0, 255)), message(msg) { }
        
        int Draw(SDL_Renderer** renderer)
        {
            scrollLevel = 0;
            
            Box::Draw(renderer);
            
            return ERR_OK;
        }
        
        int Component()
        {
            (*screen->GetUiHandlerPointer())->DisableButtons();
            
            XYToWH();
            
            std::vector<std::string> lines = Utils::String::Split(message, '\n');
            
            int lY = 0;
            
            for (uint i = 0; i < lines.size(); i++)
            {
                Ui::Label* label = new Ui::Label(x + borderSize, y + borderSize + lY, -1, -1, Ui::Color(126, 0, 0, 255), Ui::Color(255, 255, 255, 255), lines.at(i), 24, ::screen->GetResource("fonts/freemono.ttf"));
                label->SetParent(this);
                label->Resolve();
                
                if (label->GetW() >= w)
                {
                    int lineTar = std::ceil((float)label->GetW() / (float)w);
                    int last = 0;
                    
                    delete label;
                    
                    for (int j = 0; j < lineTar; j++)
                    {
                        std::string msg = "";
                        int diff = w * (j + 1);
                        int overflow = label->GetW() - diff;
                        int size = label->GetW() - overflow;
                        float part = size / (float)label->GetW();
                        int tar = std::round((float)lines.at(i).length() * part);
                        
                        if (j + 1 == lineTar)
                            msg = lines.at(i).substr(last, lines.at(i).length());
                        else
                            msg = lines.at(i).substr(last, tar);
                        
                        Ui::Label* nLabel = new Ui::Label(x + borderSize, y + borderSize + lY, -1, -1, Ui::Color(126, 0, 0, 255), Ui::Color(255, 255, 255, 255), msg, 24, ::screen->GetResource("fonts/freemono.ttf"));
                        nLabel->SetParent(this);
                        ::screen->AddComponent(nLabel);
                        
                        lY += 24 + 2;
                        last = tar;
                    }
                }
                else
                {
                    screen->AddComponent(label);
                    
                    lY += 24 + 2;
                }
            }
            
            Ui::Button* close = new Ui::Button(x + borderSize, y + h - borderSize - 25, -1, -1, Ui::Color(126, 0, 0, 255), Ui::Color(255, 255, 255, 255), "X Close", 24, ::screen->GetResource("fonts/freemono.ttf"), &ErrClose, &ErrHovering, &ErrNotHovering);
            close->SetParent(this);
            close->Enable();
            ::screen->AddComponent(close);
        }
        
        static uint Type() { return UI_OVERLAY; }
        uint Type_() { Ui::Overlay::Type(); }
        
        virtual ~ErrorBox() { }
        
        
        
        static int ErrClose(Ui::Button* button, int mouseButton, int type)
        {
            if (mouseButton == SDL_BUTTON_LEFT && type == SDL_MOUSEBUTTONUP)
            {
                Ui::ErrorBox* err = ::screen->FindComponent<Ui::ErrorBox>();
                
                for (uint i = (*::screen->GetComponentsPointer()).size() - 1; i > 0; i--) //Needs to be done backwards
                {
                    if ((*::screen->GetComponentsPointer()).at(i)->GetParent() == err)
                    {
                        delete (*::screen->GetComponentsPointer()).at(i);
                        (*::screen->GetComponentsPointer()).erase((*::screen->GetComponentsPointer()).begin() + i);
                    }
                }
                
                for (uint i = (*::screen->GetButtonsPointer()).size() - 1; i > 0; i--) //Also needs to be done backwards
                {
                    if ((*::screen->GetButtonsPointer()).at(i)->GetParent() == err)
                    {
                        (*::screen->GetButtonsPointer()).erase((*::screen->GetButtonsPointer()).begin() + i);
                    }
                }
                
                (*::screen->GetComponentsPointer()).erase((*::screen->GetComponentsPointer()).end() - 1);
                
                (*::screen->GetUiHandlerPointer())->EnableButtons();
                
                delete err;
            }
            
            return ERR_OK;
        }
        
        static int ErrHovering(Ui::Button* button)
        {
            button->GetBackgroundPointer()->SetRed(255);
            button->GetBackgroundPointer()->SetBlue(0);
            button->GetBackgroundPointer()->SetGreen(0);
            
            button->GetForegroundPointer()->SetRed(255);
            button->GetForegroundPointer()->SetBlue(255);
            button->GetForegroundPointer()->SetGreen(255);
            
            return ERR_OK;
        }
        
        static int ErrNotHovering(Ui::Button* button)
        {
            button->GetBackgroundPointer()->SetRed(126);
            button->GetBackgroundPointer()->SetBlue(0);
            button->GetBackgroundPointer()->SetGreen(0);
            
            button->GetForegroundPointer()->SetRed(255);
            button->GetForegroundPointer()->SetBlue(255);
            button->GetForegroundPointer()->SetGreen(255);
            
            return ERR_OK;
        }
    };
};

#endif
 
