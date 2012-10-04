#include "grillealgo.h"

inline int getValueFromRgb(QRgb &rgb) {
    return qMax(qRed(rgb), qMax(qBlue(rgb), qGreen(rgb)));
}

int Grillealgo::rapport(QRgb np, int rapport)
{
    int color = getValueFromRgb(np);
    return (int)((color * (double)rapport) / 255.0) + 0.5;
}

//QImage Grillealgo::loom_square(int maxcolor)
//{
//    if(palette.size() != maxcolor) creerpalette(maxcolor);
//    QList<int> matrice = table();
//    setImageGrille(original.width() * 4, original.height() *4);
//    seuil(matrice, 4);
//    return grille;
//}

//QImage Grillealgo::peyote(int maxcolor)
//{
//    if(palette.size() != maxcolor) creerpalette(maxcolor);
//    QList<int> matrice = table();
//    setImageGrille(original.width() * 4, original.height() * 4);
//    seuil(matrice, 4);
//    decalageY();
//    return grille;
//}

//QImage Grillealgo::brick(int maxcolor)
//{
//    if(palette.size() != maxcolor) creerpalette(maxcolor);
//    QList<int> matrice = table();
//    setImageGrille(original.width() * 4, original.height() * 4);
//    seuil(matrice, 4);
//    decalageX();
//    return grille;
//}

//void Grillealgo::setOriginal(QImage orig)
//{
//    original = orig;
//}

//void Grillealgo::setImageGrille(int largeur, int hauteur)
//{
//    grille = QImage(largeur, hauteur, QImage::Format_RGB32);
//}

//void Grillealgo::seuil(QList<int> matrice, int largeur)
//{
//    int sx = original.width();
//    int sy = original.height();
//    for(int y = 0; y < sy; y++) {
//        for(int x = 0; x < sx; x++) {
//            QRgb p = original.pixel(x, y);
//            int nh = rapport(p, matrice.length());
//            for(int my = 0; my < largeur; my++) {
//                for(int mx = 0; mx < largeur; mx++) {
//                    //On met la couleur du pixel
//                    if(nh > matrice.at(linear(mx, my, largeur))) {
//                        grille.setPixel(mposx(x,mx, largeur),
//                                        mposy(y,my, largeur),
//                                        getIntermediColor(p));
//                    }
//                    //Sinon on met du grisé
//                    else grille.setPixel(mposx(x,mx, largeur),
//                                         mposy(y,my, largeur),
//                                         qRgb(50, 50, 50));
//                }
//            }
//        }
//    }
//}

//void Grillealgo::decalageY()
//{
//    int sx = grille.width();
//    int sy = grille.height();
//    for(int y = 0; y < sy; y++) {
//        for(int x = 4; x < sx; x+=8) {
//            for(int xr = x; xr < x+4; xr++) {
//                grille.setPixel(xr, y, grille.pixel(xr, y+2));
//            }
//        }
//    }
//}

//void Grillealgo::decalageX()
//{
//    int sx = grille.width();
//    int sy = grille.height();
//    for(int y = 4; y < sy; y+=8) {
//        for(int x = 0; x < sx; x++) {
//            for(int yr = y; yr < y+4; yr++) {
//                grille.setPixel(x, yr, grille.pixel(x+2, yr));
//            }
//        }
//    }
//}
