#ifndef GRILLEALGO_H
#define GRILLEALGO_H

#include <QImage>
#include <QRgb>
#include "palette.h"
#include "matrice.h"
#include <QDebug>

inline int linear(int x, int y, int larg){ return x * larg + y; }
inline int mposx(int x, int mx, int larg){ return x * larg + mx; }
inline int mposy(int y, int my,int larg){ return y * larg + my; }

class Grillealgo
{
public:
    virtual QImage creerGrille(QImage original, int maxcolor) = 0;

protected:
    virtual void seuil(QImage original) = 0;
    virtual void decalage() = 0;
    int rapport(QRgb np, int rapport);
};

#endif // GRILLEALGO_H
