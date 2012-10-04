#include "grilletools.h"

inline int getValueFromRgb(QRgb &rgb) {
    return qMax(qRed(rgb), qMax(qBlue(rgb), qGreen(rgb)));
}

Grilletools::Grilletools() { }

Grilletools::~Grilletools() { }

int Grilletools::getPaletteSize()
{
    return palette.size();
}

QList<int> Grilletools::table(QString file)
{
    QList<int> matGrey;
    matGrey << 17 << 1 << 1 << 1;
    matGrey << 17 << 1 << 1 << 1;
    matGrey << 17 << 15 << 1 << 1;
    matGrey << 17 << 17 << 17 << 17;
    return matGrey;
}

QRgb Grilletools::getValueRgbColor(QRgb pixel) const
{
    const int value = getValueFromRgb(pixel);
    if(palette.contains(value)) return palette[value];
    QMap<int, QRgb>::const_iterator it = palette.constBegin();
     while (it != palette.constEnd()) {
         if(value < it.key()) {
             return it.value();
         }
         ++it;
     }
     return pixel;
}

QRgb Grilletools::getHueRgbColor(QRgb pixel) const
{
    QColor mycolor(pixel);
    const int hue = mycolor.hue();
    if(palette.contains(hue)) return palette[hue];
    QMap<int, QRgb>::const_iterator it = palette.constBegin();
     while (it != palette.constEnd()) {
         if(hue < it.key()) {
             return it.value();
         }
         ++it;
     }
     return pixel;
}

void Grilletools::creerpalette(int maxcolor, QString filename)
{
    QXmlStreamReader reader;
    QString f = "sources/" + filename;
    QFile file(f);
    file.open(QFile::ReadOnly | QFile::Text);
    reader.setDevice(&file);

    //Parse le XML et enregistre dans le hash
    while(!reader.atEnd()) {
        reader.readNext();
        if(reader.name() == "palette") {
            if(reader.attributes().value("max")
                    .toString().toInt() == maxcolor) {
                while(palette.size() < maxcolor) {
                    reader.readNext();
                    if(reader.name() == "color" && reader.isStartElement()) {
                        QRgb c = qRgb(reader.attributes().value("red")
                                      .toString().toInt(),
                                      reader.attributes().value("green")
                                      .toString().toInt(),
                                      reader.attributes().value("blue")
                                      .toString().toInt());
                        palette.insert(reader.attributes().value("vmax")
                                       .toString().toInt(), c);
                    }
                }
                file.close();
                return;
            }
        }
    }

    file.close();
}

