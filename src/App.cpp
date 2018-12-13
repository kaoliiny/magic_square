
#include "App.h"

App::App() :
    line(new QLineEdit(this)),
    pushButt(new QPushButton("Build magic square", this)),
    elnum(0)
{
    stringstream    ss;
    ss << "You can input only numbers from 3 till " << limit;
    this->text = new QLabel(ss.str().c_str(), this);
}
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

// Show QMainWindow
    this->resize(x, (marginBottom + elemSize) * elnum);
    this->show();

}



void            App::printMagicSqure()
{
    QString lineContent = line->text();
    int     lci = lineContent.toInt();

    if (lci < 3 || lci > limit) {
        text->setStyleSheet("QLabel { color: red; }");
    } else {
        text->setStyleSheet("QLabel { color: black; }");
        squares.push_back(new MagicSquare(lci));
    }

    line->clear();
}
void             App::catchClick()
{
    printMagicSqure();
}
