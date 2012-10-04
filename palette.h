#ifndef PALETTE_H
#define PALETTE_H

#include <QString>
#include <QMap>
#include <QColor>
#include <QRgb>
#include <QXmlStreamReader>
#include <QFile>

class Palette
{
public:
    Palette();
    ~Palette();

    void creerpalette(int maxcolor, QString filename);
    QRgb getValueRgbColor(QRgb pixel) const;
    QRgb getHueRgbColor(QRgb pixel) const;
    int getPaletteSize();

private:
    QMap<int,QRgb> palette;
};

#endif // PALETTE_H
