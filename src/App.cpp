
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

    for (QWidget *i : widgs) {
        i->resize(x, elemSize);
        i->move(0, (marginBottom + elemSize) * elnum++);
    }
    text->setTextInteractionFlags(Qt::NoTextInteraction);
    line->setMaxLength(3);
    line->setInputMask("D00");
    pushButt->setDefault(true);

    QObject::connect(pushButt, SIGNAL(clicked()), this, SLOT(catchClick()));

    this->resize(x, (marginBottom + elemSize) * elnum);
    this->show();
}



void             App::catchClick()
{
    QString lineContent = line->text();

    if (lineContent.toInt() > limit || lineContent.toInt() < 1) {
        text->setStyleSheet("QLabel { color: red; }");
    } else {
        text->setStyleSheet("QLabel { color: black; }");
        printMagicSqure(lineContent.toInt());
    }

    line->clear();
}
void            App::printMagicSqure(uint size)
{
    squares.push_back(new MagicSquare(size));
}
