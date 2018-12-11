
#include "MagicSquare.h"

MagicSquare::MagicSquare(uint size) :
    QWidget(),
    _size(size),
    _vec(new vector<uint>(size, 0))
{
    QString     sz("Magic Square ");
    sz.append(size);
    sz.append('x');
    sz.append(size);
    this->setWindowTitle(sz);
    this->resize(size * elemSize, size * elemSize);
    this->show();
}
