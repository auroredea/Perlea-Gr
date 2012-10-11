#ifndef GRILLEALGOBRICK_H
#define GRILLEALGOBRICK_H

#include "grillealgo.h"

class GrillealgoBrick : public Grillealgo
{
public:
    GrillealgoBrick();
    ~GrillealgoBrick();
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

#endif // GRILLEALGOBRICK_H
