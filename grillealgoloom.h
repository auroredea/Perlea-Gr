#ifndef GRILLEALGOLOOM_H
#define GRILLEALGOLOOM_H

#include "grillealgo.h"

class GrillealgoLoom: public Grillealgo
{
public:
    GrillealgoLoom();
    ~GrillealgoLoom();
    QImage creerGrille(QImage original, int maxcolor);

protected:
    void seuil(QImage original);
    void decalage();

private:
    Grilletools *tools;
    QImage grille;
};

#endif // GRILLEALGOLOOM_H
