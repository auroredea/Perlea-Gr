#ifndef GRILLEALGOSQUARE_H
#define GRILLEALGOSQUARE_H

#include "grillealgo.h"

class GrillealgoSquare : public Grillealgo
{
public:
    GrillealgoSquare();
    ~GrillealgoSquare();
    QImage creerGrille(QImage original, int maxcolor);

protected:
    void seuil(QImage original);
    void decalage();

private:
    Palette *palette;
    Matrice *mat;
    QImage grille;
};

#endif // GRILLEALGOSQUARE_H
