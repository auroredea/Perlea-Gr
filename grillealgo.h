#ifndef GRILLEALGO_H
#define GRILLEALGO_H

#include <QImage>
#include <QRgb>
#include <QFlags>
#include "palette.h"
#include "matrice.h"
#include <QDebug>

inline int linear(int x, int y, int larg){ return x * larg + y; }
inline int mposx(int x, int mx, int larg){ return x * larg + mx; }
inline int mposy(int y, int my,int larg){ return y * larg + my; }

class Grillealgo
{
public:
    enum Grille {
             Loom = 0x0,
             Peyote = 0x1,
             Brick = 0x2,
             Square = 0x4
         };
         Q_DECLARE_FLAGS(Grilles, Grille)

    virtual QImage creerGrille(QImage original, int maxcolor, int seedsInRow = 1) = 0;
    virtual int type() = 0;

protected:
    virtual void seuil(QImage original) = 0;
    virtual void decalage(int seedsInRow = 1) = 0;
    int rapport(QRgb np, int rapport);
};

Q_DECLARE_OPERATORS_FOR_FLAGS(Grillealgo::Grilles)

#endif // GRILLEALGO_H
