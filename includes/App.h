
#ifndef APP_H
# define APP_H

# include "main.h"
# include "MagicSquare.h"

class App : public QMainWindow {

Q_OBJECT

public:
	App();
	virtual ~App();

    void                Execute();
    void                printMagicSqure();

private:
    QLabel                  *text;
    QLineEdit               *line;
    QPushButton             *pushButt;
    vector<MagicSquare*>    squares;

    const uint              elemSize = 30;
    const uint              marginBottom = 5;
    const uint              x = 300;
    const int               limit = 100;
    uint                    elnum;

public slots:
    void                catchClick();

};

#endif // APP_H
