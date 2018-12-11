
#ifndef MAGICSQUARE_H
# define MAGICSQUARE_H

# include "main.h"

class MagicSquare : public QWidget {

Q_OBJECT

public:
    MagicSquare(uint size);
    virtual ~MagicSquare();


private:
    uint              _size;
    vector<uint>      _vec;
    vector<QLabel*>   _lab;

    const uint        elemSize = 30;
    uint              elnum;

    void              print() const;
    void              buildSquare();

};

#endif // MAGICSQUARE_H
