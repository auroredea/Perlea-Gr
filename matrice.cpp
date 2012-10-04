#include "matrice.h"

Matrice::Matrice() { }

Matrice::~Matrice() { }

QList<int> Matrice::table(QString file)
{
    QList<int> matGrey;
    matGrey << 17 << 1 << 1 << 1;
    matGrey << 17 << 1 << 1 << 1;
    matGrey << 17 << 15 << 1 << 1;
    matGrey << 17 << 17 << 17 << 17;
    return matGrey;
}

int Matrice::getLargeur()
{
    return 4;
}
