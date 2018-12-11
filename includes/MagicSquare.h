
#ifndef MAGICSQUARE_H
# define MAGICSQUARE_H

# include "main.h"

class MagicSquare : public QWidget {

Q_OBJECT

public:
    MagicSquare(uint size);
    virtual ~MagicSquare() {};

private:
    uint              _size;
    vector<uint>      *_vec;

    const uint              elemSize = 15;
    uint                    elnum;

};

#endif // MAGICSQUARE_H
