
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
    uint              **MS;
    vector<QLabel*>   _lab;

    uint              elemSize;
    uint              elnum;

    void              print();
    void              buildSquare();

};

#endif // MAGICSQUARE_H
