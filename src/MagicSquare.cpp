
#include "MagicSquare.h"

MagicSquare::MagicSquare(uint size) :
    QWidget(),
    _size(size),
    MS(new uint*[size]),
    _lab(vector<QLabel*>(size * size, nullptr))
{
    stringstream    sz;
    sz << size << 'x' << size << " Square";
    this->setWindowTitle(QString(sz.str().c_str()));

    elemSize = (size < 10 ? 1 :
        (size < 100 ? 2 :
        (size < 1000 ? 3 :
        (size < 10000 ? 4 :
        (size < 100000 ? 5 :
        (size < 1000000 ? 6 :
        (size < 10000000 ? 7 :
        (size < 100000000 ? 8 :
        (size < 1000000000 ? 9 :
        10))))))))) * 5;
    elemSize = elemSize < 30 ? 30 : elemSize;

    for (uint i = 0; i < size; i++) {
        MS[i] = new uint[size];
        bzero(MS[i], sizeof(*MS[i]) * size);
    }

    this->buildSquare();
    this->print();
}
MagicSquare::~MagicSquare()
{
    for (QLabel *i : _lab) {
        delete i;
    }
}



void                MagicSquare::print()
{
    const uint   ses = _size * elemSize;
    uint         curX = 0;
    uint         curY = 0;
    uint         i = 0;
    uint         j = 0;

    for (QLabel *l : _lab) {
        l = new QLabel(to_string(MS[i][j++]).c_str(), this);
        j == _size && !(j = 0) && i++;

        l->setTextInteractionFlags(Qt::NoTextInteraction);
        l->resize(elemSize, elemSize);
        l->move(curX, curY);

        curX += elemSize;
        curX == ses && !(curX = 0) && (curY += elemSize);
    }

    this->resize(ses + elemSize, ses + elemSize);
    this->show();
}

void                MagicSquare::buildSquare()
{
   uint i, j, x;

   uint row = 0;                       // start position of row
   uint col = _size / 2;               // and column

   for ( i = 0; i < _size ; i++ ) {
        for ( j = 0 ; j < _size; j++ )
            MS[i][j] = 0;              //initialize to 0 your matrix
   }

   MS[row][col] = 1;                   //position to start the counting

   for ( x = 2; x <= _size * _size; x++ )
   {
      int r = row - 1, c = col - 1;    // test positions
      if (r < 0) r += _size;
      if (c < 0) c += _size;
      if (MS[r][c] > 0) {
        row++;
        if ( row >= _size )
            row -= _size;
      } else {
         row = r;
         col = c;
      }
      MS[row][col] = x;
   }

   for ( i = 0; i < _size; i++ ) {
        for ( j = 0; j < _size; j++ )
            cout << MS[i][j] << " ";
        cout << endl;
   }
}
