#ifndef GRILLEALGOSQUARE_H
#define GRILLEALGOSQUARE_H

#include "grillealgo.h"

class GrillealgoSquare : public Grillealgo
{
public:
    GrillealgoSquare();
    ~GrillealgoSquare();
    QImage creerGrille(QImage original, int maxcolor, int seedsInRow);
    int type();

protected:
    void seuil(QImage original);
    void decalage(int seedsInRow);

private:
    Palette *palette;
    Matrice *mat;
    QImage grille;
};

#endif // GRILLEALGOSQUARE_H
