#ifndef GRILLETOOLS_H
#define GRILLETOOLS_H

#include <QString>
#include <QMap>
#include <QColor>
#include <QRgb>
#include <QXmlStreamReader>
#include <QFile>

class Grilletools
{
public:
    Grilletools();
    ~Grilletools();

    QList<int> table(QString file = "");
    void creerpalette(int maxcolor, QString filename);
    QRgb getValueRgbColor(QRgb pixel) const;
    QRgb getHueRgbColor(QRgb pixel) const;
    int getPaletteSize();

private:
    QMap<int,QRgb> palette;
};

#endif // GRILLETOOLS_H
