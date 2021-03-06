#ifndef GRILLEWINDOW_H
#define GRILLEWINDOW_H

#include <QDialog>
#include <QString>
#include <QImage>
#include <QFileDialog>
#include <QMessageBox>
#include <QDateTime>
#include "grillealgoloom.h"
#include "grillealgopeyote.h"
#include "grillealgosquare.h"
#include "grillealgobrick.h"
#include <QDebug>

namespace Ui {
    class Grillewindow;
}

class Grillewindow : public QDialog
{
    Q_OBJECT
public:
    explicit Grillewindow(QWidget *parent = 0);
    ~Grillewindow();
    void setHomepath(QString homepath);
    void setComportement(Grillealgo* choice);
    QImage getGrille();
    QString saveGrille(QImage img);

    int maxColor;
    int seedsInRow;
    bool isCopied;

protected:
    void connectAll();
    void showPreview(QString filename);

protected slots:
    void openImage();
    void accept();

private:
    Ui::Grillewindow *ui;
    QString homePath;
    Grillealgo* comportement;
    QString copyPath;
};

#endif // GRILLEWINDOW_H
