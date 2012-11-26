#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QString>
#include <QFileDialog>
#include <QDesktopWidget>
#include <QDesktopServices>
#include <QRect>
#include <QMessageBox>
#include "grillewindow.h"
#include "helpwindow.h"
#include <QDebug>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

protected:
    void connectAll();
    void shortcutAll();
    QString getHomePath();
    QSize getResolution();
    void showImg(QString filename);
    void showImg(QImage image);

protected slots:
    void openImage();
    void saveImage();
    void openDialogLoom();
    void openDialogPeyote();
    void openDialogSquare();
    void openDialogBrick();
    void openApropos();
    void openManuel();
    
private:
    Ui::MainWindow *ui;
    Grillewindow *gwindow;
    Helpwindow *hwindow;
    QString homePath;
};

#endif // MAINWINDOW_H
