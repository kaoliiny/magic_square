
#ifndef APP_H
# define APP_H

# include <QApplication>
# include <QtWidgets>
// # include <QMainWindow>
// # include <QLabel>
// # include <QLineEdit>

# include "MagicSquare.h"

using namespace std;


class App {

public:
	App();
	~App();

    void    showWindow();
    bool    catchClick();
    void    putError();
    void    printMagicSqure();

private:
    QMainWindow         Window;
    QLineEdit           text;
    QLineEdit           line;
    QPushButton         pushButt;

    static const int    win_x = 300;
    static const int    win_y = 120;

};

#endif // APP_H
