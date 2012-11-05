#include "grillealgosquare.h"

GrillealgoSquare::GrillealgoSquare(): grille(QImage(0,0))
{
    palette = new Palette;
    mat = new Matrice;
}

GrillealgoSquare::~GrillealgoSquare()
{
    delete palette;
    delete mat;
}

int GrillealgoSquare::type()
{
    return Grillealgo::Square;
}

QImage GrillealgoSquare::creerGrille(QImage original, int maxcolor, int seedsInRow)
{
    if(palette->getPaletteSize() != maxcolor)
        palette->creerpalette(maxcolor, "paletteshue.xml");
    grille = QImage(original.width() * 4,
                    original.height() * 4,
                    QImage::Format_RGB32);
    seuil(original);
    return grille;
}

void GrillealgoSquare::decalage(int seedsInRow)
{
    return;
}

void GrillealgoSquare::seuil(QImage original)
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

