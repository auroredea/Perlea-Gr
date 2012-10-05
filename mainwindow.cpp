#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    gwindow(new Grillewindow),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->centralWidget->setStyleSheet("QWidget { background-image: url(img/pattern.jpg) }");
    connectAll();
    shortcutAll();
    homePath = QDesktopServices::storageLocation(
                QDesktopServices::HomeLocation);
    //gwindow = new Grilleloomwindow(0, homePath);
    QSize resolution = getResolution();
    this->setMinimumSize(resolution -= QSize(30, 80));
}

MainWindow::~MainWindow()
{
    delete ui;
    delete gwindow;
}

void MainWindow::showImg(QString filename)
{
    QImage i(filename);
    showImg(i);
}

void MainWindow::showImg(QImage i)
{
    QPixmap pic = QPixmap::fromImage(i);
    ui->actionEnregistrer->setEnabled(true);
    ui->image->setPixmap(pic);
}

void MainWindow::connectAll()
{
    connect(ui->actionOuvrir, SIGNAL(triggered()), this, SLOT(openImage()));
    connect(ui->actionEnregistrer, SIGNAL(triggered()), this, SLOT(saveImage()));
    connect(ui->actionQuitter, SIGNAL(triggered()), this, SLOT(close()));
    connect(ui->actionLoom, SIGNAL(triggered()), this, SLOT(openDialogLoom()));
    connect(ui->actionPeyote, SIGNAL(triggered()), this, SLOT(openDialogPeyote()));
    connect(ui->actionSquare, SIGNAL(triggered()), this, SLOT(openDialogSquare()));
    connect(ui->actionBrick, SIGNAL(triggered()), this, SLOT(openDialogBrick()));
}

void MainWindow::shortcutAll()
{
    ui->actionOuvrir->setShortcut(QKeySequence("Ctrl+O"));
    ui->actionEnregistrer->setShortcut(QKeySequence("Ctrl+S"));
    ui->actionQuitter->setShortcut(QKeySequence("Ctrl+Q"));
    ui->actionLoom->setShortcut(QKeySequence("Ctrl+Alt+L"));
    ui->actionPeyote->setShortcut(QKeySequence("Ctrl+Alt+P"));
    ui->actionSquare->setShortcut(QKeySequence("Ctrl+Alt+S"));
    ui->actionBrick->setShortcut(QKeySequence("Ctrl+Alt+B"));
}

void MainWindow::openImage()
{
    QString title = tr("Ouvrir l'image");
    QString directory = homePath;
    QString filename = QFileDialog::getOpenFileName(
                this,
                title,
                directory,
                tr("Images (*.jpg *.jpeg *.bmp *.png)")
                );
    if(filename != "") {
        showImg(filename);
    }
}

void MainWindow::saveImage()
{
    QString filename = QFileDialog::getSaveFileName(
                this,
                tr("Enregistrer le fichier"),
                homePath,
                tr("Images (*.jpg *.jpeg *.bmp *.png)"));
    if(filename != "") {
        bool saved = ui->image->pixmap()->toImage().save(filename);
        if(!saved) QMessageBox::critical(this,
                       tr("Enregistrement"),
                       tr("Erreur dans la sauvegarde de l'image"),
                       QMessageBox::Ok);
    }
}

void MainWindow::openDialogLoom()
{
    Grillealgo *choice  = new GrillealgoLoom();
    gwindow->setComportement(choice);
    int response = gwindow->exec();
    if(response) {
        QImage newimage = gwindow->getGrille();
        if(gwindow->isCopied) {
            gwindow->saveGrille(newimage);
        }
        showImg(newimage);
    }
}

void MainWindow::openDialogPeyote()
{
    Grillealgo *choice  = new GrillealgoPeyote();
    gwindow->setComportement(choice);
    int response = gwindow->exec();
    if(response) {
        QImage newimage = gwindow->getGrille();
        showImg(newimage);
    }
}

void MainWindow::openDialogSquare()
{
    Grillealgo *choice  = new GrillealgoSquare();
    gwindow->setComportement(choice);
    int response = gwindow->exec();
    if(response) {
        QImage newimage = gwindow->getGrille();
        showImg(newimage);
    }
}

void MainWindow::openDialogBrick()
{
    Grillealgo *choice  = new GrillealgoBrick();
    gwindow->setComportement(choice);
    int response = gwindow->exec();
    if(response) {
        QImage newimage = gwindow->getGrille();
        showImg(newimage);
    }
}

QSize MainWindow::getResolution()
{
    QDesktopWidget desktop;
    QRect available = desktop.screenGeometry(this);
    return available.size();
}
