#ifndef GRILLETOOLS_H
#define GRILLETOOLS_H

#include <QString>
#include <QMap>
#include <QRgb>
#include <QXmlStreamReader>
#include <QFile>

class Grilletools
{
public:
    Grilletools();
    ~Grilletools();

    QList<int> table(QString file = "");
    void creerpalette(int maxcolor);
    QRgb getIntermediColor(QRgb) const;
    int getPaletteSize();

private:
    QMap<int,QRgb> palette;
};

#endif // GRILLETOOLS_H
