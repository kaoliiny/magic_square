
#include "MagicSquare.h"

MagicSquare::MagicSquare(uint size) :
    QWidget(),
    _size(size),
    _vec(vector<uint>(size * size, 1, size * size)),
    _lab(vector<QLabel*>(size * size))
{
    stringstream    sz;
    sz << size << 'x' << size << " Square";
    this->setWindowTitle(QString(sz.str().c_str()));            

    this->buildSquare();
    this->print();
}
MagicSquare::~MagicSquare()
{
    for (QLabel *i : _lab)
        delete i;
}



void                MagicSquare::print() const
{
    const int    ses = _size * elemSize;
    int          i = 0;
    int          curX = 0;
    int          curY = 0;

    for (auto &l : _lab) {
        l = new QLabel(to_string(_vec[i++]).c_str(), this);
        l->setTextInteractionFlags(Qt::NoTextInteraction);
        l->resize(elemSize, elemSize);
        l->move(curX, curY);

        curX += elemSize;
        if (curX == ses) {
            curX = 0;
            curY += elemSize;
        }
    }

    this->resize(ses + elemSize, ses + elemSize);
    this->show();
}

void                MagicSquare::buildSquare()
{
    static int      offset = 0;
    int             sums[size * 2 + 2];
    int             d = 0;

    sums[d] = getDiagSum();
    for (int i = 0; i < _size; i++) {
        sums[d] = getRebGorSum();
    }
    for (int i = 0; i < _size; i++) {
        sums[d] = getRebVectSum();
    }
}
