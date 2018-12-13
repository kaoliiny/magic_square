
#ifndef MAGICSQUARE_H
# define MAGICSQUARE_H

# include "main.h"

#include <cstdlib>
#include <cstring>
#include <cctype>

#define WRAP(xory, width) \
    ( ((width) + (xory)) % (width) )

#define D2_1(x, y, width) \
    ( WRAP((y), (width)) * (width) + WRAP((x), (width)) )

#define D2_1A(A, width) \
    D2_1( (A)[0], (A)[1], (width) )

#define ADDA(A, xi, yi) \
    ( ((A)[0] += (xi)), ((A)[1] += (yi)) )

#define YXLOOP(yi, yc, xi, xc) \
    for(int y = (yi); y < (yc); ++y) \
        for(int x = (xi); x < (xc); ++x)

#define SWAPA(A, i, j) \
    ( ((A)[(i)] = (A)[(i)] + (A)[(j)]), \
      ((A)[(j)] = (A)[(i)] - (A)[(j)]), \
      ((A)[(i)] = (A)[(i)] - (A)[(j)]) )

#define MAGSQ_EXSUM(n) \
    ( (n) * ((n) * (n) + 1) / 2 )

#define MAGSQ_XSUM(ms, y) \
    magsq_linesum((ms), (y), magsq_xcoord)

#define MAGSQ_YSUM(ms, x) \
    magsq_linesum((ms), (x), magsq_ycoord)

#define MAGSQ_DSUM(ms) \
    magsq_linesum((ms), 0, magsq_dcoord)

#define MAGSQ_DISUM(ms) \
    magsq_linesum((ms), 0, magsq_dicoord)

#define LAMBDA_GET_COORD(name, arg_seed, arg_var, arg_width, formula) \
    int name(int arg_seed, int arg_var, int arg_width){ return (formula); }

typedef int *   magsq_t;
/* magsq_t: { width, [array of size width^2] } */


class MagicSquare : public QWidget {

Q_OBJECT

public:
    MagicSquare(uint size);
    virtual ~MagicSquare();

private:
    const int         _size;
    int               *MS;
    vector<QLabel*>   _lab;

    uint              elemSize;

    void              printSquare();
    magsq_t           buildSquare();
    magsq_t           buildOddSquare(int n);
    magsq_t           buildEvenSquare(int n);
    magsq_t           buildDoublyEvenSquare(int n);

};


#endif // MAGICSQUARE_H
