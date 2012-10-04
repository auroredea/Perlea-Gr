#ifndef GRILLEALGOPEYOTE_H
#define GRILLEALGOPEYOTE_H

#include "grillealgo.h"

class GrillealgoPeyote : public Grillealgo
{
public:
    GrillealgoPeyote();
    ~GrillealgoPeyote();
    QImage creerGrille(QImage original, int maxcolor);

protected:
    void seuil(QImage original);
    void decalage();

private:
    Grilletools *tools;
    QImage grille;
};

#endif // GRILLEALGOPEYOTE_H
