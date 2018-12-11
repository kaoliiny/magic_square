
#include "App.h"

int main(int argc, char **argv)
{
    QApplication        app(argc, argv);
    App                 MS;

    MS.showWindow();
    while (MS.catchClick())
        MS.putError();
    MS.printMagicSqure();

    return app.exec();
}
