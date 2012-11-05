#include "grillewindow.h"
#include "ui_grillewindow.h"

Grillewindow::Grillewindow(QWidget *parent):
    QDialog(parent),
    maxColor(4),
    isCopied(false),
    homePath(""),
    seedsInRow(1),
    comportement(NULL),
    ui(new Ui::Grillewindow)
{
    ui->setupUi(this);
    copyPath = QCoreApplication::applicationDirPath();
    copyPath += "/copies";
    ui->label_path->setText("(Répertoire : " + copyPath + ")");
    connectAll();
}

Grillewindow::~Grillewindow()
{
    delete ui;
    delete comportement;
}

void Grillewindow::setHomepath(QString homepath)
{
    homePath = homepath;
}

void Grillewindow::setComportement(Grillealgo *choice)
{
    comportement = choice;
    if(choice->type() == Grillealgo::Peyote) {
        ui->label_form3->setEnabled(true);
        ui->donneeSeedsInRow->setEnabled(true);
    }
    else {
        ui->label_form3->setEnabled(false);
        ui->donneeSeedsInRow->setEnabled(false);
    }
}

QImage Grillewindow::getGrille()
{
    if(ui->image->pixmap() == 0 || comportement == NULL) {
        return QImage();
    }
    else return comportement->creerGrille(
                ui->image->pixmap()->toImage(),
                maxColor,
                seedsInRow);
}

void Grillewindow::showPreview(QString filename)
{
    QImage i(filename);
    QPixmap pic = QPixmap::fromImage(i);
    ui->image->setText("");
    pic  = pic.scaled(ui->image->size(),
                      Qt::KeepAspectRatio);
    ui->image->setPixmap(pic);
}

void Grillewindow::connectAll()
{
    connect(ui->actionOuvrir, SIGNAL(pressed()), this, SLOT(openImage()));
}

void Grillewindow::openImage()
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
        showPreview(filename);
    }
}

QString Grillewindow::saveGrille(QImage img)
{
    QDateTime now = QDateTime::currentDateTime();
    QString random_name = "/" + now.toString("ddMMyyyyhmsz") + ".png";
        bool saved = img.save(copyPath + random_name, "PNG", 0);
    if(!saved) QMessageBox::critical(this,
                   tr("Enregistrement"),
                   tr("Erreur dans la sauvegarde de l'image"),
                   QMessageBox::Ok);
    return random_name;
}

void Grillewindow::accept()
{
    if(ui->image->pixmap() == 0) {
        done(0);
    }
    else {
        QString nb = ui->donneeMaxColor->currentText();
        maxColor = nb.toInt();
        QString nb2 = ui->donneeSeedsInRow->currentText();
        seedsInRow = nb2.toInt();
        isCopied = ui->donneeCopie->isChecked();
        done(1);
    }
}
