#include "grillealgo.h"

inline int getValueFromRgb(QRgb &rgb) {
    return qMax(qRed(rgb), qMax(qBlue(rgb), qGreen(rgb)));
}

int Grillealgo::rapport(QRgb np, int rapport)
{
    int color = getValueFromRgb(np);
    return (int)((color * (double)rapport) / 255.0) + 0.5;
}
