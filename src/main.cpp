
#include "App.h"

int main(int argc, char **argv)
{
    QApplication        app(argc, argv);
    App                 MS;

    MS.Execute();

    return app.exec();
}
