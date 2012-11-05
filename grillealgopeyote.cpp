#include "grillealgopeyote.h"

GrillealgoPeyote::GrillealgoPeyote(): grille(QImage(0,0))
{
    palette = new Palette;
    mat = new Matrice;
}

GrillealgoPeyote::~GrillealgoPeyote()
{
    delete palette;
    delete mat;
}

int GrillealgoPeyote::type()
{
    return Grillealgo::Peyote;
}

QImage GrillealgoPeyote::creerGrille(QImage original, int maxcolor, int seedsInRow)
{
    if(palette->getPaletteSize() != maxcolor)
        palette->creerpalette(maxcolor, "paletteshue.xml");
    grille = QImage(original.width() * 4,
                    original.height() * 4,
                    QImage::Format_RGB32);
    seuil(original);
    decalage(seedsInRow);
    return grille;
}

void GrillealgoPeyote::decalage(int seedsInRow)
{
    int rangs = 8*seedsInRow;
    int decal = rangs/2;
    int sx = grille.width()-4;
    int sy = grille.height()-4;
    for(int y = 0; y < sy; y++) {
        for(int x = decal; x < sx; x+=rangs) {
            for(int xr = x; xr < x+decal; xr++) {
                grille.setPixel(xr, y, grille.pixel(xr, y+2));
            }
        }
    }
}

void GrillealgoPeyote::seuil(QImage original)
{
    QList<int> matrice = mat->table();
    int sx = original.width();
    int sy = original.height();
    int largeur = mat->getLargeur();
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
                                        palette->getHueRgbColor(p));
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
