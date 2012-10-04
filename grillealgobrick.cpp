#include "grillealgobrick.h"

GrillealgoBrick::GrillealgoBrick(): grille(QImage(0,0))
{
    tools = new Grilletools;
}

GrillealgoBrick::~GrillealgoBrick()
{
    delete tools;
}

QImage GrillealgoBrick::creerGrille(QImage original, int maxcolor)
{
    if(tools->getPaletteSize() != maxcolor) tools->creerpalette(maxcolor);
    grille = QImage(original.width() * 4,
                    original.height() * 4,
                    QImage::Format_RGB32);
    seuil(original);
    decalage();
    return grille;
}

void GrillealgoBrick::decalage()
{
    int sx = grille.width();
    int sy = grille.height();
    for(int y = 4; y < sy; y+=8) {
        for(int x = 0; x < sx; x++) {
            for(int yr = y; yr < y+4; yr++) {
                grille.setPixel(x, yr, grille.pixel(x+2, yr));
            }
        }
    }
}

void GrillealgoBrick::seuil(QImage original)
{
    QList<int> matrice = tools->table();
    int sx = original.width();
    int sy = original.height();
    int largeur = 4; //Dans Grilletools à l'avenir ??
    for(int y = 0; y < sy; y++) {
        for(int x = 0; x < sx; x++) {
            QRgb p = original.pixel(x, y);
            int nh = rapport(p, matrice.length());
            for(int my = 0; my < 4; my++) {
                for(int mx = 0; mx < largeur; mx++) {
                    //On met la couleur du pixel
                    if(nh > matrice.at(linear(mx, my, largeur))) {
                        grille.setPixel(mposx(x,mx, largeur),
                                        mposy(y,my, largeur),
                                        tools->getIntermediColor(p));
                    }
                    //Sinon on met du grisé
                    else grille.setPixel(mposx(x,mx, largeur),
                                         mposy(y,my, largeur),
                                         qRgb(50, 50, 50));
                }
            }
        }
    }
}
