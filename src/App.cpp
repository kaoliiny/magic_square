
#include "App.h"

App::App() :
    Window(),
    text("You can input only numbers from 1 till 100!", &Window),
    line(&Window),
    pushButt("Build magic square", &Window)
{
    const int            elemSize = win_y / (3 * 2);

    Window.resize(win_x, win_y);
    // placeWidget(text);
    // placeWidget(line);
    // placeWidget(pushButt);

    text.resize(win_x, elemSize);
    text.move(0, elemSize * 0 + 1);
    line.resize(win_x, elemSize);
    line.move(0, elemSize * 1 + 1);
    pushButt.resize(win_x, elemSize);
    pushButt.move(0, elemSize * 2 + 1);
}
App::~App()
{

}



void            App::showWindow()
{
    Window.show();
}

bool             App::catchClick()
{
    return false;
}

void            App::putError()
{

}

void            App::printMagicSqure()
{

}

