
#include "App.h"

App::App() :
    text(new QLabel("You can input only numbers from 1 till 90!", this)),
    line(new QLineEdit(this)),
    pushButt(new QPushButton("Build magic square", this)),
    elnum(0)
{}
App::~App()
{
    delete text;
    delete line;
    delete pushButt;
    for (auto *i : squares) {
        delete i;
    }
};


void    App::Execute()
{
    vector<QWidget*>     widgs;
    widgs.push_back(text);
    widgs.push_back(line);
    widgs.push_back(pushButt);

// Installing QWidgets to QMainWindow
    for (QWidget *i : widgs) {
        i->resize(x, elemSize);
        i->move(0, (marginBottom + elemSize) * elnum++);
    }
    text->setTextInteractionFlags(Qt::NoTextInteraction);
    line->setMaxLength(3);
    line->setInputMask("D00");
    pushButt->setDefault(true);

// Set up event listeners and handlers
    QObject::connect(pushButt, SIGNAL(clicked()), this, SLOT(catchClick()));

    // keyEnterReceiver*        key = new keyEnterReceiver();
    // line->installEventFilter(key);

// Show QMainWindow
    this->resize(x, (marginBottom + elemSize) * elnum);
    this->show();

    // delete key;
}



void            App::printMagicSqure()
{
    QString lineContent = line->text();

    if (lineContent.toInt() > limit || lineContent.toInt() < 1) {
        text->setStyleSheet("QLabel { color: red; }");
    } else {
        text->setStyleSheet("QLabel { color: black; }");
        squares.push_back(new MagicSquare( lineContent.toInt() ));
    }

    line->clear();
}
void             App::catchClick()
{
    printMagicSqure();
}
// bool            keyEnterReceiver::eventFilter(QObject *obj, QEvent *event)
// {
//     if (event->type()==QEvent::KeyPress) {
//         QKeyEvent* key = static_cast<QKeyEvent*>(event);
//         if ( (key->key()==Qt::Key_Enter) || (key->key()==Qt::Key_Return) ) {
//             dynamic_cast<App*>(obj)->printMagicSqure();
//         } else {
//             return QObject::eventFilter(obj, event);
//         }
//         return true;
//     } else {
//         return QObject::eventFilter(obj, event);
//     }
//     return false;
// }
