#ifndef MATRICE_H
#define MATRICE_H

#include <QList>
#include <QString>

class Matrice
{
public:
    Matrice();
    ~Matrice();

    QList<int> table(QString file = "");
    int getLargeur();
};

#endif // MATRICE_H
