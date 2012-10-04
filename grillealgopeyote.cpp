#include "grillealgopeyote.h"

GrillealgoPeyote::GrillealgoPeyote(): grille(QImage(0,0))
{
    tools = new Grilletools;
}

GrillealgoPeyote::~GrillealgoPeyote()
{
    delete tools;
}

QImage GrillealgoPeyote::creerGrille(QImage original, int maxcolor)
{
    if(tools->getPaletteSize() != maxcolor) tools->creerpalette(maxcolor);
    grille = QImage(original.width() * 4,
                    original.height() * 4,
                    QImage::Format_RGB32);
    seuil(original);
    decalage();
    return grille;
}

void GrillealgoPeyote::decalage()
{
    int sx = grille.width();
    int sy = grille.height();
    for(int y = 0; y < sy; y++) {
        for(int x = 4; x < sx; x+=8) {
            for(int xr = x; xr < x+4; xr++) {
                grille.setPixel(xr, y, grille.pixel(xr, y+2));
            }
        }
    }
}

void GrillealgoPeyote::seuil(QImage original)
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
