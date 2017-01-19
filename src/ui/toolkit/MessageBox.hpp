#ifndef UI_MESSAGEBOX_HPP_
#define UI_MESSAGEBOX_HPP_

#include "ui/toolkit/Label.hpp"
#include "ui/toolkit/Color.hpp"
#include "ui/toolkit/Button.hpp"
#include "ui/toolkit/Overlay.hpp"
#include "misc/utils/String.hpp"

namespace Ui
{
    class MessageBox : public Ui::Overlay
    {
    protected:
        std::string message;
        
        bool center;
        
    public:
        MessageBox(std::string msg, bool alignCenter = false) : Overlay(8, 8, WINDOW_W() - 8, WINDOW_H() - 8, Ui::Color(0, 0, 0, 100), 2, Ui::Color(255, 255, 255, 255)), message(msg), center(alignCenter) { XYToWH(); }
        
        int Draw(SDL_Renderer** renderer)
        {
            Box::Draw(renderer);
            
            return ERR_OK;
        }
        
        int Component()
        {
            (*::screen->GetUiHandlerPointer())->DisableButtons();
            
            std::vector<std::string> lines = Utils::String::Split(message, '\n');
            
            int lY = 0;
            
            for (uint i = scrollLevel; i < lines.size(); i++)
            {
                Ui::Label* label = new Ui::Label(x + borderSize, y + borderSize + lY, -1, -1, Ui::Color(0, 0, 0, 255), Ui::Color(255, 255, 255, 255), lines.at(i), 14, ::screen->GetResource("fonts/freemono.ttf"));
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
                        
                        Ui::Label* nLabel = new Ui::Label(x + borderSize, y + borderSize + lY, -1, -1, Ui::Color(0, 0, 0, 255), Ui::Color(255, 255, 255, 255), msg, 14, ::screen->GetResource("fonts/freemono.ttf"));
                        nLabel->SetParent(this);
                        nLabel->Resolve();
                        
                        if (center)
                            nLabel->SetX((w - nLabel->GetW()) / 2);
                        
                        ::screen->AddComponent(nLabel);
                        
                        lY += 14 + 2;
                        last = tar;
                    }
                }
                else
                {
                    if (center)
                        label->SetX((w - label->GetW()) / 2);
                    
                    ::screen->AddComponent(label);
                    
                    lY += 14 + 2;
                }
                
                if (y + lY + 2 * borderSize + 16 > h) //If it's too high, do not continue
                    break;
            }
            
            Ui::Button* close = new Ui::Button(x + borderSize, y + h - borderSize - 25, -1, -1, Ui::Color(0, 0, 0, 255), Ui::Color(255, 255, 255, 255), "X Close", 24, ::screen->GetResource("fonts/freemono.ttf"), &MsgClose);
            close->SetParent(this);
            close->Enable();
            screen->AddComponent(close);
            
            return ERR_OK;
        }
        
        static uint Type() { return UI_OVERLAY; }
        uint Type_() { Ui::Overlay::Type(); }
        
        virtual ~MessageBox() { }
        
        
        
        static int MsgClose(Ui::Button* button, int mouseButton, int type)
        {
            if (mouseButton == SDL_BUTTON_LEFT && type == SDL_MOUSEBUTTONUP)
            {
                Ui::MessageBox* msg = ::screen->FindComponent<Ui::MessageBox>();
                
                for (uint i = (*::screen->GetComponentsPointer()).size() - 1; i > 0; i--) //Needs to be done backwards
                {
                    if ((*::screen->GetComponentsPointer()).at(i)->GetParent() == msg)
                    {
                        (*::screen->GetComponentsPointer()).erase((*::screen->GetComponentsPointer()).begin() + i);
                    }
                }
                
                for (uint i = (*::screen->GetButtonsPointer()).size() - 1; i > 0; i--) //Also needs to be done backwards
                {
                    if ((*::screen->GetButtonsPointer()).at(i)->GetParent() == msg)
                    {
                        delete (*::screen->GetButtonsPointer()).at(i);
                        (*::screen->GetButtonsPointer()).erase((*::screen->GetButtonsPointer()).begin() + i);
                    }
                }
                
                (*::screen->GetComponentsPointer()).erase((*::screen->GetComponentsPointer()).end() - 1);
                
                (*::screen->GetUiHandlerPointer())->EnableButtons();
                
                delete msg;
            }
            
            return ERR_OK;
        }
    };
};

#endif
 
