
#include "MagicSquare.h"

MagicSquare::MagicSquare(uint size) :
    _size(size),
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
        10))))))))) * 18;
    elemSize = elemSize < 30 ? 30 : elemSize;

    MS = this->buildSquare() + 1;
    this->printSquare();
}
MagicSquare::~MagicSquare()
{
    delete (MS - 1);
    for (QLabel *i : _lab)
        delete i;
}


void
MagicSquare::printSquare()
{
    const uint   ses = _size * elemSize;
    uint         curX = 0;
    uint         curY = 0;
    uint         i = 0;

    for (QLabel *l : _lab) {
        l = new QLabel(to_string(MS[i++]).c_str(), this);

        l->setTextInteractionFlags(Qt::NoTextInteraction);
        l->resize(elemSize, elemSize);
        l->move(curX, curY);

        curX += elemSize;
        curX == ses && !(curX = 0) && (curY += elemSize);
    }

    this->resize(ses + elemSize, ses + elemSize);
    this->show();
}


magsq_t
magsq_struct(int n)
{
    int *out = new int[1 + n * n];

    bzero(out, sizeof(int) * (1 + n * n));
    *out = n;
    return out;
}

magsq_t
MagicSquare::buildSquare()
{
    int         n = _size;

    if (n % 4 == 0)
        return buildDoublyEvenSquare(n);
    else if (n % 2 == 0)
        return buildEvenSquare(n);
    else
        return buildOddSquare(n);
}


int
magsq_linesum(magsq_t ms, int seed, int (*get_coord)(int,int,int))
{
    int         *map = ms + 1;
    int         width = *ms;
    int         total = 0;

    for (int var = 0; var < width; ++var)
        total += map[get_coord(seed, var, width)];

    return total;
}

magsq_t
MagicSquare::buildOddSquare(int n)
{
    magsq_t     out = magsq_struct(n);
    int         *map = out + 1;
    int         coord[2] = {n / 2, 0};

    map[D2_1A(coord, n)] = 1;

    for (int i = 1; i < n*n; ++i) {
        ADDA(coord, +1, -1);

        while(map[D2_1A(coord, n)] > 0 || (coord[0] == -1 && coord[1] == n))
            ADDA(coord, -1, +2);

        coord[0] = WRAP(coord[0], n);
        coord[1] = WRAP(coord[1], n);
        map[D2_1A(coord, n)] = i + 1;
    }

    return out;
}

magsq_t
MagicSquare::buildDoublyEvenSquare(int n)
{
    magsq_t     out = magsq_struct(n);
    int         *map = out + 1;

    for (int i = 0; i < n*n; ++i)
        map[i] = i + 1;

    YXLOOP(0, n/4, 0, n/4)
        SWAPA(map, D2_1(x, y, n), D2_1((n-1)-x, (n-1)-y, n));

    YXLOOP(0, n/4, 3 * n/4, n)
        SWAPA(map, D2_1(x, y, n), D2_1((n-1)-x, (n-1)-y, n));

    YXLOOP(n/4, 2 * n/4, n/4, 3 * n/4)
        SWAPA(map, D2_1(x, y, n), D2_1((n-1)-x, (n-1)-y, n));

    return out;
}

magsq_t
MagicSquare::buildEvenSquare(int n)
{
    magsq_t     out = magsq_struct(n);
    magsq_t     quadrant = buildOddSquare(n / 2) + 1;
    int         *map = out + 1;
    int const   qn = n/2;
    int const   qsq = qn * qn;
    int const   xl = (qn + 1) / 2;
    int const   xr = xl - 2;
    int const   ym = xl - 1;

    YXLOOP(0, qn, 0, qn) {
        map[D2_1(x, y, n)] = quadrant[D2_1(x, y, qn)];
        map[D2_1(x + qn, y + qn, n)] = quadrant[D2_1(x, y, qn)] + qsq;
        map[D2_1(x + qn, y, n)] = quadrant[D2_1(x, y, qn)] + 2 * qsq;
        map[D2_1(x, y + qn, n)] = quadrant[D2_1(x, y, qn)] + 3 * qsq;
    }

    delete (quadrant - 1);

    YXLOOP(0, qn, 0, xl)
        if ( (x == 0 && y != ym)
        || (x == xl - 1 && y == ym)
        || (x > 0 && x < xl - 1) )
            SWAPA(map, D2_1(x, y, n), D2_1(x, y + qn, n));

    YXLOOP(0, qn, n - xr, n)
        SWAPA(map, D2_1(x, y, n), D2_1(x, y + qn, n));

    return out;
}
