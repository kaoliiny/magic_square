
#ifndef APP_H
# define APP_H

# include <QApplication>
# include <QtWidgets>
 
# include <vector>
# include <unistd.h>

# include "MagicSquare.h"

using namespace std;


class App : public QMainWindow {

Q_OBJECT

public:
	App();
	virtual ~App() {};

    void                printMagicSqure();
    void                Execute();

private:
    QLabel              *text;
    QLineEdit           *line;
    QPushButton         *pushButt;

    const uint          elemSize = 30;
    const uint          marginBottom = 5;
    const uint          x = 300;
    uint                elnum;


public slots:
    void                catchClick();

};

#endif // APP_H
