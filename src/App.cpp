
#include "App.h"
App::App() :
    text(new QLabel("You can input only numbers from 1 till 100!", this)),
    line(new QLineEdit(this)),
    pushButt(new QPushButton("Build magic square", this)),
    elnum(0)
{

}

void    App::Execute()
{
    vector<QWidget*>     widgs;
    widgs.push_back(text);
    widgs.push_back(line);
    widgs.push_back(pushButt);

    uint l = 0;
    // for (QWidget *i in widgs) {
    while ( l < widgs.size() ) {
        QWidget *i = widgs[l++];
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

    if (lineContent.toInt() > 100 || lineContent.toInt() < 1) {
        text->setStyleSheet("QLabel { color: red; }");
    } else {
        text->setStyleSheet("QLabel { color: black; }");
        printMagicSqure();
    }

    line->clear();
}
void            App::printMagicSqure()
{
    // MagicSqure      square();
}
