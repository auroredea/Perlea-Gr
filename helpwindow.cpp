#include "helpwindow.h"
#include "ui_helpwindow.h"

Helpwindow::Helpwindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Helpwindow)
{
    ui->setupUi(this);
    //Helpwindow : manuel et licence ouvrent un navigateur web
    //QDesktopServices::openUrl(QUrl::fromLocalFile(fichier));
}

Helpwindow::~Helpwindow()
{
    delete ui;
}

void Helpwindow::setType(int t)
{
    //type = t;
}

int Helpwindow::getType()
{
    return type;
}

void Helpwindow::accept()
{
   //Suivant le type afficher le bon texte
    done(1);
}
