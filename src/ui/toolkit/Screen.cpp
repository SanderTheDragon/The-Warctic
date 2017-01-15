#include "ui/toolkit/Screen.hpp"

#include "Config.hpp"
#include "misc/Logger.hpp"
#include "misc/Errors.hpp"

#include "ui/toolkit/List.hpp"
#include "ui/toolkit/Overlay.hpp"

Ui::Screen::Screen()
{
    resourceHandler = new ResourceHandler();
    uiHandler = new UiHandler();
}

void Ui::Screen::Draw(SDL_Renderer** renderer)
{
    uiHandler->Draw(renderer);
}

void Ui::Screen::Update(int mouseX, int mouseY)
{
    uiHandler->Update(mouseX, mouseY);
}

Ui::Screen::~Screen()
{
    delete uiHandler;
    delete resourceHandler;
}
