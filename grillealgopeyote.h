#ifndef GRILLEALGOPEYOTE_H
#define GRILLEALGOPEYOTE_H

#include "grillealgo.h"

class GrillealgoPeyote : public Grillealgo
{
public:
    GrillealgoPeyote();
    ~GrillealgoPeyote();
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

#endif // GRILLEALGOPEYOTE_H
